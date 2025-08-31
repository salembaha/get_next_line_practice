#include "get_next_line.h"

// FUNCTION_read_to_stash (read until '\0', strchr&strjoin), FUNCTION__extract_line (cuts at '\0', strchr&substr), FUNCTION_stash_after_line (use strlen&substr&free)
static char	*read_to_stash(int fd, char *stash);
static char	*extract_line(char *stash);
static char	*stash_after_line(char *stash);
//

char	get_next_line(int fd)
{
	static char	*stash;
	char		line;

	stash = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	stash = read_to_stash(fd, stash);
	if (!stash)
		return NULL;
	line = extract_line(stash);
	stash = stash_after_line(stash);
	return (line);
}
