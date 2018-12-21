#ifndef __RED-BLACK_TREE_H__
#define __RED-BLACK_TREE_H__

/* Macro defines */
#define LEAF NULL

/* Structures */
/* Colors used in the RB tree. */
enum colors{
  RED,
  BLACK
};

struct node{
  struct node* left;
  struct node* right;
  struct node* parent;
  //void *data;
  int key;
  enum colors color;
};

struct rbtree{
  struct node *root;
  int nodeCounts;

  /* Compare function */
  /* If node1 > node2, return value result > 0;
   * If node1 < node2, return value result < 0;
   * If node1 = node2, return value result = 0;
   * */
  void NodeCmp(struct node node1, struct node node2, int *result);
};

/* Export function declaration */
void init_rb_tree(struct rbtree *rb, void *NodeCmpFunc)
{
    do{
        rb->root = NULL;
        rb->nodeCounts = 0;
        rb->NodeCmp = NULL;
    }while(0);
}

#define insert_rb_node(struct rbtree *rb, struct node node1) \
        do{ \
          insert(rb->root, node1);
          delete_one_child(struct rbtree *rb); \
          rb->nodeCounts--; \
        }while(0);
#define REPLACENODE_RB_NODE(struct rbtree *rb, struct node node1) \

#define DELETENODE_RB_NODE(struct rbtree *rb, struct node node1) \
        do{ \
          delete_one_child(struct rbtree *rb); \
          rb->nodeCounts--; \
        }while(0);

#define DESTROY_RB_TREE(struct rbtree *rb) \
        do{ \
          destroy_rb_tree(rb->root); \
          rb->root = NULL; \
          rb->nodeCounts = 0; \
          rb->NodeCmp = NULL; \
        }while(0);

#endif