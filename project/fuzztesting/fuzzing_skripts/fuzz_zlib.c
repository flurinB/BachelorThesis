#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>

// This harness reads raw data from a file, then tries to uncompress it
// We don't care about the decompressed output; we just want to see if it crashes.

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    // Open the file from AFL++ (the @@ argument)
    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    // Read file into memory
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    if (fsize <= 0) {
        fclose(fp);
        return 0; // empty file is not interesting, but not a crash
    }

    unsigned char *in_buf = malloc(fsize);
    if (!in_buf) {
        fclose(fp);
        return 1;
    }

    fread(in_buf, 1, fsize, fp);
    fclose(fp);

    // We'll allocate a decompression buffer with some arbitrary size
    // For large inputs or deeper fuzzing, you might want to choose something bigger or dynamic
    size_t out_size = 1024 * 1024; // 1 MB output
    unsigned char *out_buf = malloc(out_size);
    if (!out_buf) {
        free(in_buf);
        return 1;
    }

    // Prepare uncompress
    uLongf dest_len = out_size;
    int ret = uncompress(out_buf, &dest_len, in_buf, fsize);

    // If uncompress fails, it's not necessarily a crash. We just ignore the return code.
    // But if there's a bug in zlib, it might crash or segfault during uncompress.

    free(in_buf);
    free(out_buf);
    return 0;
}
