#include <fu.h>
#include <iostream>

#define URL "file:///tmp/upload"
#define FILE_1 "imagen.jpg"
#define FILE_2 "texto.txt"

using std::cout;
using std::cerr;
using std::endl;

/**
 * The main function.
 */
int main (int argc, char **argv)
{
	cout << "FileUpload test program" << endl << endl;

	// Init file upload function
	if ( fu_init() ) {
		cerr << "Error to initialize File Upload " << endl;
		return -1;
	}

	// finish file upload function
	fu_end();

	return 0;
}
/*
 * Editor modelines  -  https://www.wireshark.org/tools/modelines.html
 *
 * Local variables:
 * c-basic-offset: 8
 * tab-width: 8
 * indent-tabs-mode: t
 * End:
 *
 * vi: set shiftwidth=8 tabstop=8 noexpandtab:
 * :indentSize=8:tabSize=8:noTabs=false:
 */
