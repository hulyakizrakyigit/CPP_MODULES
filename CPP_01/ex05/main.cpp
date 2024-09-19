#include "Harl.hpp"

int main()
{
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	return 0;
}
// Üye İşlevler ve İşaretçiler
// Üye İşlevler (Member Functions): Bir sınıfın işlevleri, sınıfın nesnelerine ait olan işlevlerdir ve genellikle this işaretçisi kullanılarak nesne üzerinde işlem yapar.

// İşaretçiler (Pointers) ve Üye İşlevler:

// İşaretçi Kullanımı: C++'da bir üye işlevin adresini saklamak ve bu işlevi dinamik olarak çağırmak için işaretçileri kullanabilirsiniz. Bu, işlev işaretçileri (function pointers) olarak bilinir.
// İşlev İşaretçileri: Sınıf içindeki bir işlevin adresini saklayan bir işaretçi türüdür. Bu işaretçiler, belirli bir işlevi çağırmak için kullanılabilir.
