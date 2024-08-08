#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int countdown;

    // Meminta input dari user
    printf("Masukkan waktu hitung mundur dalam menit: ");
    scanf("%d", &countdown);

    // Mengonversi menit ke detik
    countdown *= 60;

    printf("Menghitung mundur selama %d menit...\n", countdown / 60);

    // Menghitung mundur
    while (countdown > 0) {
        printf("Waktu tersisa: %d menit %d detik\n", countdown / 60, countdown % 60);
        sleep(1);  // Tidur selama 1 detik
        countdown--;
    }

    // Setelah hitungan mundur selesai, device sleep
    printf("Waktu habis! Memasukkan device ke dalam mode sleep.\n");
    system("pmset sleepnow");  // Menjalankan perintah sleep pada macOS

    return 0;
}
