#include <stdio.h>
#include <fu.h>

/**
 * CURL handle session.
 */
static CURL *fu_curl = NULL;

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

	return 0;
}

void fu_end(void)
{

	if (fu_curl)
		curl_easy_cleanup(fu_curl);
	fu_curl = NULL;
	curl_global_cleanup();
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
