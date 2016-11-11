#ifndef TP8_CODE_TUTEURS_H_
#define TP8_CODE_TUTEURS_H_

#define _CMD_LIST  "LIST"
#define _CMD_ACQ_I "ACQUIRE_ID"
#define _CMD_ACQ_S "ACQUIRE_SUBJ"
#define _CMD_REL   "RELEASE"
#define _CMD_QUIT  "QUIT"
#define _MSG_ERR   "ERROR"
#define _MSG_MAXLENGTH 100
#define _RPLY_MAXMSGS 100

#define _SRV_PORT  7776


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
 */
int init_tutors(char *, struct tutor **);

/*
 * Copy a tutors list
 * @param[in]	tutors  	The head of the tutor list to be copied
 * @return					The head of the copy of list
 */
struct tutor *copy(struct tutor *);


#endif /* TP8_CODE_TUTEURS_H_ */
