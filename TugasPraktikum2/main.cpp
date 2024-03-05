#include <iostream>
#include <vector>
#include <string>

#include "include/clearscreen.hpp"
#include "include/loading.hpp"
#include "include/pauseconsole.hpp"
#include "include/intro.hpp"

#include "include/reverseTranspose.hpp"
#include "include/dataItem.hpp"

void deco() {
    for (int i = 0; i < 85; i++) {
        std::cout << "=" ;
    }
}

void deco2() {
    for (int i = 0; i < 85; i++) {
        std::cout << "_" ;
    }
}

int main(int, char**){
    using namespace std;

    Intro();

    Loading();

    int program;

    bool ulang = true;
    do 
    {
        deco();
        cout << "\n" ;

        cout << "\t\t\t" << "|" << "\tList Program:\t    " << "|" << "\n";
        cout << "1. Program Tabel Data dari Matrix" << "\n";
        cout << "2. Program Transpose Matrix Searah Jarum Jam" << "\n";
        cout << "3. Exit" << "\n";

        deco();
        cout << "\n";

        cout << "Masukkan pilihan: ";
        cin >> program;

        deco2();
        cout << endl;

        switch (program)
        {
        case 1:
        {
            PauseConsole();
            ClearScreen();

            int A, B;

            deco();
            cout << "\n";

            cout << "Masukkan jumlah Baris: ";
            cin >> A;

            cout << "Masukkan jumlah kolom: ";
            cin >> B;

            /* Kita menggunakan vector dikarenakan array yang kita buat itu berbentuk dinamis. Artinya
               kita tidak mengetahui batasan pasti dari array tersebut. Untuk perbandingan, array standar itu
               biasanya berbentuk seperti ini:
               A[10][10]
               Array diatas memiliki batas baris dan kolom sebanyak 10. Kita tidak perlu menggunakan vector
               jika bentuk array yang dimiliki itu seperti diatas. */
            vector<vector<int>> matrix(A, vector<int>(B));

            // Input data ke array
            cout << "\nMasukkan Element Matrix:\n";
            for (int i = 0; i < A; ++i) {
                for (int j = 0; j < B; ++j) {
                    cout << "Masukkan nilai dari matrix a[" << i << "][" << j << "] : ";
                    cin >> matrix[i][j];
                }
            }

            PauseConsole();
            ClearScreen();

            deco2();
            cout << "\n";

            // Print output Matrix
            cout << "Matrix:\n";
            for (int i = 0; i < A; i++) {
                for (int j = 0; j < B; j++) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }

            // Memanggil function untuk mentranspose Matrix ke arah jarum jam
            reverseTranspose(matrix);

            // Print output Matrix yang sudah diputar searah jarum jam
            cout << "\nMatrix setelah diputar 90 Derajat:\n";
            for (int i = 0; i < A; i++) {
                for (int j = 0; j < B; j++) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }

            cout << "\nProgram ini dibuat oleh Mr. Farid Noer Hakim :D\n";

            deco2();
            cout << endl;

        }
            PauseConsole();
            ClearScreen();
            break;
        case 2:
        {
            PauseConsole();
            ClearScreen();

            deco();
            cout << "\n";

            int numItems, numDays;

            cout << "Masukkan jumlah barang: ";
            cin >> numItems;

            cout << "\n";

            // Vector untuk menyimpan nama dari data
            vector<string> itemNames(numItems);

            for (int i = 0; i < numItems; ++i) {
                cout << "Sebutkan nama barang ke-" << i + 1 << ": ";
                cin >> itemNames[i];
            }

            cout << "\n";
            deco2();
            cout << "\n";

            cout << "Masukkan jumlah hari: ";
            cin >> numDays;

            cout << "\n";

            // Untuk menyimpan jumlah dari data
            vector<vector<int>> quantities(numDays, vector<int>(numItems));

            // Input jumlah data di setiap hari
            for (int i = 0; i < numDays; ++i) {
                for (int j = 0; j < numItems; ++j) {
                    cout << "Masukkan jumlah " << itemNames[j]
                            << " di hari " << i + 1 << ": ";
                    cin >> quantities[i][j];
                }
            }

            deco();
            cout << "\n";

            // Print nama dari setiap data
            cout << "\t";
            for (const auto& x : itemNames) {
                cout << x << "\t";
            }
            cout << endl;

            // Print hari dan jumlah data
            for (int i = 0; i < numDays; ++i) {
                // Print hari
                cout << i + 1 << "\t";

                // Print jumlah dari setiap data
                for (int j = 0; j < numItems; ++j) {
                    cout << quantities[i][j] << "\t";
                }
                cout << endl;
            }

            cout << "\n";
            deco();
            cout << "\n";

            int inputElement;
            cout << "\nTolong masukkan element yang ingin dilihat: ";
            cin >> inputElement;

            // Memanggil struct dan function dari file lain.
            dataItem item = itemDetails(itemNames, quantities, inputElement);
            dataItem* itemPtr = &item;

            cout << "\nNama: " << item.name << "\n";
            cout << "Hari: " << item.day << "\n";
            cout << "Jumlah: " << item.amount << "\n";
            cout << "Alamat: " << itemPtr << "\n";

            cout << "\nProgram ini dibuat oleh Mr. Farid Noer Hakim :D\n\n" ;

            deco();
            cout << "\n";
        }
            PauseConsole();
            ClearScreen();
            break;

        case 3:
            cout << "Keluar dari program..." << endl;
            ulang = false;
            PauseConsole();
            ClearScreen();
            break;
        
        default:
            cout << "Angka yang anda pilih tidak ada di pilihan!" << endl ;
            PauseConsole();
            ClearScreen();
            break;
        }

    } while (ulang);

    return 0;
}
