// FIXME: 42 header

#ifndef CHAR_PAGE_H
# define CHAR_PAGE_H

# include <stdint.h>

char	get_char(uint8_t page, uint8_t charid);
char	*get_char_page(uint8_t page);
char	conv_char(char c, uint8_t *page);

char	*page1(void);
char	*page2(void);
char	*page3(void);
char	*page4(void);
char	*page5(void);
char	*page6(void);
char	*page7(void);

#endif // CHAR_PAGE_H
