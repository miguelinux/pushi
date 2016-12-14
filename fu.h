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

enum FU_CODE {
	FU_NO  = 0,
	FU_YES = 1
};

/**
 * Initialize function.
 * This function initialize the basic stuff.
 */
int fu_init(void);

/**
 * Cleanup function.
 */
void fu_end(void);

void fu_set_url(const char *);

void fu_set_image_file(const char *);

void fu_set_text_file(const char *);

void fu_remove_expectheader(enum FU_CODE);

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
