// FIXME: 42 header

#ifndef CHAR_PAGE_H
# define CHAR_PAGE_H

# include <stdint.h>

char	get_char(uint8_t page, uint8_t charid);
char	*get_char_page(uint8_t page);
char	conv_char(char c, uint8_t *page);

char	*page1();
char	*page2();
char	*page3();
char	*page4();
char	*page5();
char	*page6();
char	*page7();

#endif // CHAR_PAGE_H
