#include "Base.hpp"

class Pakaian : public Base {
protected:
  std::string pemilik;
  float ukuran;

public:
  Pakaian(std::string pemilik, float ukuran) {}

  ~Pakaian() {}

  virtual void pakai() = 0;

protected:
  std::ostream &status() { return std::cout; }
};

class Baju : public Pakaian {
public:
  static int defaultTahun;
  static int defaultUkuran;

protected:
  const int tahun;

public:
  Baju() {}

  Baju(std::string pemilik, float ukuran, int tahun) {}

  void pakai() {}

  ~Baju() {}

protected:
  std::ostream &status() { return std::cout; }
};

class BajuPolo : public Baju {
private:
  static int jumlah;

protected:
  double panjangKerah = 0.5;
  int keluaranKe;

public:
  BajuPolo(std::string pemilik, int tahun) {}

  BajuPolo(std::string pemilik, int tahun, double panjangKerah) {}

  BajuPolo(BajuPolo &other) {}

  ~BajuPolo() {}

protected:
  std::ostream &status() {}
};

class Celana : public Pakaian {
private:
  bool pakeSabuk;

public:
  Celana(std::string pemilik, float ukuran, bool pakeSabuk) {}

  Celana(Celana &other, std::string pemilikBaru) {}

  void pakai() {}

  ~Celana() {}

protected:
  std::ostream &status() {}
};