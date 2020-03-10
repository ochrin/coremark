#
# "main" pseudo-component makefile.
#
# (Uses default behaviour of compiling all source files in directory, adding 'include' to include path.)


CFLAGS += $(subst ",,$(CONFIG_OPTIMIZATION)) -D$(subst ",,$(CONFIG_RUN_TYPE))=1