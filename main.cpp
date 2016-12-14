#include <fu.h>
#include <iostream>

#define URL "file:///tmp/upload"
#define IMG1 "img1.jpg"
#define IMG2 "img2.jpg"
#define TXT1 "txt1.txt"
#define TXT2 "txt2.txt"

using std::cout;
using std::cerr;
using std::endl;

/**
 * The main function.
 */
int main (void)
{
	cout << "FileUpload test program" << endl << endl;

	// Init file upload function
	if ( fu_init() ) {
		cerr << "Error to initialize File Upload " << endl;
		return -1;
	}

	fu_set_url(URL);

	fu_set_image_file(IMG1);
	fu_set_text_file(TXT1);
	// See fu.h documentation regarding the following function
	fu_remove_expectheader(FU_NO);
	fu_upload();

	fu_set_image_file(IMG2);
	fu_set_text_file(TXT2);
	// See fu.h documentation regarding the following function
	fu_remove_expectheader(FU_YES);
	fu_upload();


	// finish file upload function
	fu_end();

	cout << "exit succesful" << endl;
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
