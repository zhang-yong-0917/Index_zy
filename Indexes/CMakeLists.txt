AUX_SOURCE_DIRECTORY(. DIR_TEST1_SRCS)
add_executable ( Indexes ${DIR_TEST1_SRCS} rb_tree.cpp rb_tree.h Segment_Tree.cpp Segment_Tree.h rbtree_test.cpp index_create.cpp index_create.h)