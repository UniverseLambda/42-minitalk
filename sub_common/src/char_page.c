#include <char_page.h>

#include <stdlib.h>

char	get_char(uint8_t page, uint8_t charid)
{
	char	*page_ptr;

	page_ptr = get_char_page(page);
	if (page_ptr == NULL)
		return ('\0');
	return (page_ptr[charid]);
}

char	*get_char_page(uint8_t page)
{
	if (page == 1)
		return (page1());
	if (page == 2)
		return (page2());
	if (page == 3)
		return (page3());
	if (page == 4)
		return (page4());
	if (page == 5)
		return (page5());
	if (page == 6)
		return (page6());
	if (page == 7)
		return (page7());
	return (NULL);
}

char	conv_char(char c, uint8_t *page)
{
	if (c < 0x20)
		return ('\0');
	*page = ((c - 0x20) / 16) + 1;
	return ((c - 0x20) % 16);
}
