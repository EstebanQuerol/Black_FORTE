FILE(GLOB_RECURSE FILES_FOUND "${FORTE_MODULE_DIR}/*CMakeLists.txt")

FOREACH(FILE ${FILES_FOUND})
  string(REPLACE "${FORTE_MODULE_DIR}" "" MODULE_NAME ${FILE})
  STRING(REGEX MATCH "^/([^/]*)/CMakeLists.txt$" MODULE_NAME ${MODULE_NAME})
  IF(MODULE_NAME)
    string(REPLACE "/CMakeLists.txt" "" MODULE_NAME "${MODULE_NAME}")
    string(REPLACE "/" "" MODULE_NAME "${MODULE_NAME}")
    LIST(APPEND MODULE_LIST ${MODULE_NAME})
  ENDIF(MODULE_NAME)
ENDFOREACH(FILE)

#MESSAGE("GLOBBING: ${MODULE_LIST2}" )
#MESSAGE("GLOBBING: ${MODULE_LIST}" )
  
  
  
SET(WRITE_FILE "")
FOREACH(MODULE ${MODULE_LIST})
  SET(WRITE_FILE "${WRITE_FILE}SET(SOURCE_GROUP_BACKUP \"\${SOURCE_GROUP}\")\n")
  SET(WRITE_FILE "${WRITE_FILE}SET(SOURCE_GROUP \"\${SOURCE_GROUP}/${MODULE}\")\n")
  SET(WRITE_FILE "${WRITE_FILE}ADD_SUBDIRECTORY(\"\${FORTE_MODULE_DIR}${MODULE}\")\n")
  SET(WRITE_FILE "${WRITE_FILE}SET(SOURCE_GROUP \"\${SOURCE_GROUP_BACKUP}\")\n")
ENDFOREACH(MODULE)

file(WRITE ${CMAKE_BINARY_DIR}/src/modules/CMakeLists_new.txt ${WRITE_FILE})
  
execute_process( COMMAND ${CMAKE_COMMAND} -E compare_files ${CMAKE_BINARY_DIR}/src/modules/CMakeLists_new.txt ${CMAKE_BINARY_DIR}/src/modules/CMakeLists.txt RESULT_VARIABLE test_not_successful OUTPUT_QUIET ERROR_QUIET )  

IF(test_not_successful)
  file(REMOVE ${CMAKE_BINARY_DIR}/src/modules/CMakeLists.txt)
  file(RENAME ${CMAKE_BINARY_DIR}/src/modules/CMakeLists_new.txt ${CMAKE_BINARY_DIR}/src/modules/CMakeLists.txt)
ENDIF( test_not_successful)  
file(REMOVE ${CMAKE_BINARY_DIR}/src/modules/CMakeLists_new.txt) 