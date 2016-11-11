#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Datatype
struct tutor {
	char id[100];
	char subj[100];
	struct tutor *next;
};

/*
 * Initialize a tutor list from a file.
 * @param[in]	filepath	The path of the file
 * @param[out]	tutors  	The head of the tutor list
 * @return					The length of the new list
 */
int init_tutors(char *filepath, struct tutor ** tutors) {
  int length = 0;
  FILE *fic = fopen(filepath, "r");
  char buf[100];
  struct tutor * head = *tutors;
	while (fgets(buf, sizeof(buf), fic)) {
		length++;
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0;
		char *space = strchr(buf, ' ');
		*space = 0;
		struct tutor *new_tutor = malloc(sizeof(struct tutor));
		strcpy(new_tutor->id, buf);
		strcpy(new_tutor->subj, space + 1);
		new_tutor->next = head;
		head = new_tutor;
		//printf("debug: init_tutors: %s - %s\n", new_tutor->id, new_tutor->subj);
	}
	fclose(fic);
	*tutors = head;
	return length;
}

/*
 * Copy a tutors list
 * @param[in]	tutors  	The head of the tutor list to be copied
 * @return					The head of the copy of list
 */
struct tutor *copy(struct tutor * tutors) {
	printf("debug: copy\n");

	if (tutors == NULL) {return NULL;}

	struct tutor *list = tutors, *new_list, *elem, *last;
	new_list = malloc(sizeof(struct tutor));
	strcpy(new_list->id, list->id);
	strcpy(new_list->subj, list->subj);
	last = new_list;
	list = list->next;
	while (list != NULL) {
		elem = malloc(sizeof(struct tutor));
		strcpy(elem->id, list->id);
		strcpy(elem->subj, list->subj);
		last->next = elem;
		last = elem;
		list = list->next;
	}
	return new_list;
}
