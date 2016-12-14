#ifndef _FU_H
#define _FU_H

#include <curl/curl.h>

#define FU_MAX_URL_LEN  90
#define FU_MAX_PATH_LEN 80

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Codes from FU.
 */
enum FU_CODE {
	FU_NO  = 0, /**< False value */
	FU_YES = 1, /**< True  value */

	FU_URL_SET	= 0x10, /**< Flag to know if URL is set */
	FU_NO_EXPECT	= 0x20, /**< Flag to remove expect header */
};

/**
 * A file upload structure.
 */
struct _sfu {
	char url[FU_MAX_URL_LEN];  /**< The URL to updoad the files */
	char img[FU_MAX_PATH_LEN]; /**< The image fullpath */
	char txt[FU_MAX_PATH_LEN]; /**< The text file fullpath */
	int  flags; /**< Config flags as shown in FU_CODE */
};

/**
 * Initialize function.
 * This function initialize the basic stuff.
 * @return 0 if no errors found.
 */
int fu_init(void);

/**
 * Cleanup function.
 */
void fu_end(void);

/**
 * Set the URL to upload the files.
 * @param url is the URL to upload the files.
 */
void fu_set_url(const char *url);

/**
 * Set the image filename tu upload.
 * The filename should be the full path.
 * @image is the full path of the image.
 */
void fu_set_image_file(const char *image);

/**
 * Set the text file to upload.
 * @textfile is the full path of the file.
 */
void fu_set_text_file(const char *textfile);

/**
 * Remove the expect header.
 *
 * When using the HttpWebRequest to POST form data using HTTP 1.1, it ALWAYS
 * adds the following HTTP header “Expect: 100-Continue”. Fixing the problem
 * has proved to be quite elusive.
 *
 * According to the HTTP 1.1 protocol, when this header is sent, the form data
 * is not sent with the initial request. Instead, this header is sent to the
 * web server which responds with 100 (Continue) if implemented correctly.
 * However, not all web servers handle this correctly, including the server to
 * which I am attempting to post data. I sniffed the headers that Internet
 * Explorer sends and noticed that it does not send this header, but my code
 * does.
 *
 * Document source: http://haacked.com/archive/2004/05/15/http-web-request-expect-100-continue.aspx/
 * More documents: https://httpstatusdogs.com/100-continue
 * https://www.w3.org/Protocols/rfc2616/rfc2616-sec8.html
 *
 * @param flag is to remove with FU_YES, or keep it with FU_NO.
 */
void fu_remove_expectheader(enum FU_CODE flag);

/**
 * Upload the files to the webserver.
 * @return 0 if no errors found.
 */
int fu_upload();

#ifdef __cplusplus
}
#endif
#endif
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
