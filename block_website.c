#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void block_website(const char *website) {
    FILE *hosts_file = fopen("/etc/hosts", "a");
    if (hosts_file == NULL) {
        perror("Gagal membuka file /etc/hosts");
        exit(EXIT_FAILURE);
    }

    fprintf(hosts_file, "127.0.0.1 %s\n", website);
    fclose(hosts_file);
    printf("Website %s telah diblokir.\n", website);
}

int main() {
    char website[256];

    printf("Masukkan website yang ingin diblokir: ");
    scanf("%255s", website); // Membatasi panjang input untuk mencegah buffer overflow

    block_website(website);

    return 0;
}
