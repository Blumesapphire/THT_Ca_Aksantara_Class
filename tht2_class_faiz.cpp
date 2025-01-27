#include <iostream>
#include <string>
using namespace std;

// Membuat class "Contact"
class Contact {
  // Atribut class "Contact"
  private:
    string nama; 
    string tempat_tinggal;
    string alamat;
    string kekuatan;

  public:
    // Fungsi untuk ngisi data contact
    void isi_contact(string name, string residence, string address, string power) {
      nama = name;
      tempat_tinggal = residence;
      alamat = address;
      kekuatan = power;
    }

    // Mendapatkan data
    string data_nama() {
      return nama;
    }
    string data_tempat_tinggal() {
      return tempat_tinggal;
    }
    string data_alamat() {
      return alamat;
    }
    string data_kekuatan() {
      return kekuatan;
    }
};

// Membuat class "PhoneBook"
class PhoneBook {
  // Atribut dari class "PhoneBook"
  private:
    // Array untuk nyimpan ada berapa kontak yang disimpan (max 8)
    Contact array_contact[8] = {};
  
  public:
  // Integer untuk menghitung jumlah kontak sekarang
    int jumlah_contact = 0;

    // Fungsi untuk nambahin contact
    void add_contact(Contact kontak) {
      if (jumlah_contact < 8) {
        // Kalau nyimpan kontaknya belum sampai 8, maka bisa langsung nambahin
        // variabel jumlah_contact nambah 1 jadi nanti kalau input lagi langsung ke elemen array selanjutnya
        array_contact[jumlah_contact] = kontak;
        jumlah_contact += 1;
      }
      else {
        // Kalau jumlah kontaknya sudah 8 berarti kontak pertama dihapus dan kontak baru masuk ke paling belakang
        for(int i = 0; i < 7; i++) {
          array_contact[i] = array_contact[i+1];
        }
        array_contact[jumlah_contact - 1] = kontak;
      }
    }

    // Fungsi menampilkan semua kontak tapi namanya doang
    void display_name() {
      // Kalau array_contact punya isi berarti bisa dicari, kalau engga ya berarti list kontaknya 0
      if (jumlah_contact > 0) {
        for (int i = 0; i < jumlah_contact; i++) {
          // data_nama() dipake untuk mengambil string nama dari class Contact
          cout << i+1 << ". " << array_contact[i].data_nama() << endl;
        }
      }
    }

    // Fungsi untuk menampilkan kontak spesifik tapi detil
    void contact_detail(int index) {
      // Index yang diinput harus valid
      if ((index > 0) || (index < jumlah_contact)) {
        Contact person = array_contact[index - 1];
        cout << "Nama: " << person.data_nama() << endl;
        cout << "Tempat Tinggal: " << person.data_tempat_tinggal() << endl;
        cout << "Alamat: " << person.data_alamat() << endl;
        cout << "Kekuatan: " << person.data_kekuatan() << endl;
      }
    }
};

// Program utama
int main() {
  // Deklarasi variabel dari class "PhoneBook"
  PhoneBook phone_book;
  int pilihan;

  pilihan = 0;
  while (pilihan != 3) {
    cout << "1. ADD \n2. SEARCH \n3. EXIT" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;

    // OPSI PILIHAN 1 (ADD)
    if (pilihan == 1) {
      // Tambahkan kontak baru
      Contact new_contact;
      string name, residence, address, power;

      cin.ignore();
      // Semua harus terisi, diperlukan pengecekan apakah terisi atau tidak
      do {
        cout << "Masukkan nama: ";
        getline(cin, name);
        if (name.empty()) {
          cout << "Nama tidak boleh kosong! Silakan masukkan ulang.\n";
        }
      } while (name.empty());

      do {
        cout << "Masukkan tempat tinggal: ";
        getline(cin, residence);
        if (residence.empty()) {
          cout << "Tempat tinggal tidak boleh kosong! Silakan masukkan ulang.\n";
        }
      } while (residence.empty());

      do {
        cout << "Masukkan alamat: ";
        getline(cin, address);
        if (address.empty()) {
          cout << "Alamat tidak boleh kosong! Silakan masukkan ulang.\n";
        }
      } while (address.empty());

      do {
        cout << "Masukkan kekuatan: ";
        getline(cin, power);
        if (power.empty()) {
          cout << "Kekuatan tidak boleh kosong! Silakan masukkan ulang.\n";
        }
      } while (power.empty());

      new_contact.isi_contact(name, residence, address, power);
      phone_book.add_contact(new_contact);
    }

    // OPSI PILIHAN 2 (SEARCH)
    else if (pilihan == 2) {
      // Nyari kontak
      phone_book.display_name();

      int index;
      // Kalau jumlah kontaknya 0 berarti tidak ada yang tersimpab
      if (phone_book.jumlah_contact == 0) {
        cout << "Tidak ada kontak yang tersimpan." << endl;
      }
      // Kalau jumlah kontaknya minimal 1 berarti ada yang tersimpan
      else {
        do {
          // Input angka yang tersedia (menyesuaikan dengan jumlah kontaknya)
          // Kalau jumlah kontaknya ada 3 tapi inputnya 5 maka harus input ulang
          cout << "Masukkan angka untuk melihat detail kontak (1 - " << phone_book.jumlah_contact << "): ";
          cin >> index;

          if ((index < 1) || (index > phone_book.jumlah_contact)) {
          cout << "Angka tidak valid! Silakan masukkan angka antara 1 dan " << phone_book.jumlah_contact << "." << endl;
          }  
        } while ((index < 1) || (index > phone_book.jumlah_contact));
        phone_book.contact_detail(index);
      }
    }

    // OPSI PILIHAN 3 (EXIT)
    else {
      cout << "Exit." << endl;
    }
  }
  


}