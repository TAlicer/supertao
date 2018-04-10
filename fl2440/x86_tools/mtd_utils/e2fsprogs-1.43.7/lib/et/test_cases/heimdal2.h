/*
 * heimdal2.h:
 * This file is automatically generated; please do not edit it.
 */

#include <et/com_err.h>

#define KADM_RCSID                               (-1783126272L)
#define KADM_NO_REALM                            (-1783126271L)
#define KADM_NO_CRED                             (-1783126270L)
#define KADM_BAD_KEY                             (-1783126269L)
#define KADM_NO_ENCRYPT                          (-1783126268L)
#define KADM_NO_AUTH                             (-1783126267L)
#define KADM_WRONG_REALM                         (-1783126266L)
#define KADM_NO_ROOM                             (-1783126265L)
#define KADM_BAD_VER                             (-1783126264L)
#define KADM_BAD_CHK                             (-1783126263L)
#define KADM_NO_READ                             (-1783126262L)
#define KADM_NO_OPCODE                           (-1783126261L)
#define KADM_NO_HOST                             (-1783126260L)
#define KADM_UNK_HOST                            (-1783126259L)
#define KADM_NO_SERV                             (-1783126258L)
#define KADM_NO_SOCK                             (-1783126257L)
#define KADM_NO_CONN                             (-1783126256L)
#define KADM_NO_HERE                             (-1783126255L)
#define KADM_NO_MAST                             (-1783126254L)
#define KADM_NO_VERI                             (-1783126253L)
#define KADM_INUSE                               (-1783126252L)
#define KADM_UK_SERROR                           (-1783126251L)
#define KADM_UK_RERROR                           (-1783126250L)
#define KADM_UNAUTH                              (-1783126249L)
#define KADM_DATA                                (-1783126248L)
#define KADM_NOENTRY                             (-1783126247L)
#define KADM_NOMEM                               (-1783126246L)
#define KADM_NO_HOSTNAME                         (-1783126245L)
#define KADM_NO_BIND                             (-1783126244L)
#define KADM_LENGTH_ERROR                        (-1783126243L)
#define KADM_ILL_WILDCARD                        (-1783126242L)
#define KADM_DB_INUSE                            (-1783126241L)
#define KADM_INSECURE_PW                         (-1783126240L)
#define KADM_PW_MISMATCH                         (-1783126239L)
#define KADM_NOT_SERV_PRINC                      (-1783126238L)
#define KADM_IMMUTABLE                           (-1783126237L)
#define KADM_PASS_Q_NULL                         (-1783126208L)
#define KADM_PASS_Q_TOOSHORT                     (-1783126207L)
#define KADM_PASS_Q_CLASS                        (-1783126206L)
#define KADM_PASS_Q_DICT                         (-1783126205L)
extern const struct error_table et_kadm_error_table;
extern void initialize_kadm_error_table(void);

/* For compatibility with Heimdal */
extern void initialize_kadm_error_table_r(struct et_list **list);

#define ERROR_TABLE_BASE_kadm (-1783126272L)

/* for compatibility with older versions... */
#define init_kadm_err_tbl initialize_kadm_error_table
#define kadm_err_base ERROR_TABLE_BASE_kadm
