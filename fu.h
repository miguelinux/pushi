#ifndef _FU_H
#define _FU_H

#include <curl/curl.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * A file upload structure.
 */
struct _sfu {
	char url[80]; /**< The URL to updoad the files */

};


/**
 * Initialize function.
 * This function initialize the basic stuff.
 */
int fu_init();

/**
 * Cleanup function.
 */
int fu_end();

#ifdef __cplusplus
extern "C" {
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
