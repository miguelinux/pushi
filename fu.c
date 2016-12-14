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
static void fu_set_conf(enum FU_CODE code)
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

	fu_set_conf(FU_INIT_OK);

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
	sprintf(fu_conf.url, "%s", url);
	/* Keep that we already set the URL */
	fu_conf.flags |= FU_URL_SET;
}

void fu_set_image_file(const char *image)
{
	sprintf(fu_conf.img, "%s", image);
}

void fu_set_text_file(const char *textfile)
{
	sprintf(fu_conf.txt, "%s", textfile);
}

void fu_remove_expectheader(enum FU_CODE flag)
{
	/* if FU_YES, then we remove expect else we keep it */
	if (flag)
		fu_conf.flags |= FU_NO_EXPECT;
	else
		fu_conf.flags &= ~FU_NO_EXPECT;
}

int fu_upload()
{
	CURLcode res;
	CURLFORMcode resForm;

	struct curl_httppost *post = NULL;
	struct curl_httppost *last = NULL;

	struct curl_slist *headerlist  = NULL;

	struct curl_forms forms[3];

	static const char buf[] = "Expect:";

	forms[0].option = CURLFORM_FILE;
	forms[0].value  = fu_conf.img;
	forms[1].option = CURLFORM_FILE;
	forms[1].value  = fu_conf.txt;
	forms[2].option  = CURLFORM_END;

	resForm = curl_formadd(&post, &last, CURLFORM_COPYNAME, "pictures",
				CURLFORM_ARRAY, forms, CURLFORM_END);
	if (resForm) {
		fprintf(stderr, "Error(%d): fail in formadd.\n", resForm);
		curl_formfree(post);
		return -resForm;
	}

	/* initialize custom header list (stating that Expect: 100-continue
	 * is not wanted */
	headerlist = curl_slist_append(headerlist, buf);


	fu_set_conf(FU_INIT_OK | FU_URL_SET);

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
