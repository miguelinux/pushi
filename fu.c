#include <stdio.h>
#include <string.h>
#include <fu.h>

/**
 * CURL handle session.
 */
static CURL *fu_curl = NULL;

static struct _sfu fu_conf;

/**
 * Initialize the fu_conf.
 */
static void fu_conf_init(enum FU_CODE code)
{
	// Verify if we want to reset URL
	if (! (code & FU_URL_SET) )
		memset(fu_conf.url, 0, FU_MAX_URL_LEN);
	memset(fu_conf.img, 0, FU_MAX_PATH_LEN);
	memset(fu_conf.txt, 0, FU_MAX_PATH_LEN);

	fu_conf.flags = code;
}

int fu_init(void)
{
	CURLcode res;

	res = curl_global_init(CURL_GLOBAL_ALL);
	if (res != CURLE_OK) {
		fprintf(stderr, "Error(%d): fail in global init.\n", res);
		return -res;
	}

	fu_curl = curl_easy_init();
	if (fu_curl == NULL) {
		fprintf(stderr, "Error: fail in easy init.\n");
		curl_global_cleanup();
		return -1;
	}

	fu_conf_init(0);

	return 0;
}

void fu_end(void)
{

	if (fu_curl)
		curl_easy_cleanup(fu_curl);
	fu_curl = NULL;
	curl_global_cleanup();
}

void fu_set_url(const char *url)
{
}

void fu_set_image_file(const char *image)
{
}

void fu_set_text_file(const char *textfile)
{
}

void fu_remove_expectheader(enum FU_CODE flag)
{
}

int fu_upload()
{
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
