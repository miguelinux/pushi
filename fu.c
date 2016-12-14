#include <fu.h>

/**
 * CURL handle session.
 */
static CURL *fu_curl = NULL;

int fu_init() {

  CURLcode res;

  res = curl_global_init(CURL_GLOBAL_ALL);
  if (res != CURLE_OK) {
	  fprintf(stderr, "Error(%d): something went wrong and you cannot use curl functions.\n", res);
	  return (int)res;
  }

  return 0;
}

int fu_end() {
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
