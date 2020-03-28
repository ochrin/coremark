idf_component_register(SRCS "main.c" 
							"core_list_join.c"
							"core_main.c"
							"core_matrix.c"
							"core_portme.c"
							"core_state.c"
							"core_util.c"
                    INCLUDE_DIRS ".")

target_compile_options(${COMPONENT_LIB} PRIVATE ${CONFIG_OPTIMIZATION} -D${CONFIG_RUN_TYPE}=1)