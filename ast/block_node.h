#ifndef __ZU_AST_BLOCK_H__
#define __ZU_AST_BLOCK_H__

#include <cdk/ast/sequence_node.h>

namespace zu {

  class block_node: public cdk::basic_node {
      cdk::sequence_node *_declaration;
      cdk::sequence_node *_instruction;
      
  public:
    inline block_node(int lineno, cdk::sequence_node *declaration, cdk::sequence_node *instruction) :
        cdk::basic_node(lineno), _declaration(declaration), _instruction(instruction) {
    }
    
  public:
    inline cdk::sequence_node *declaration() {
      return _declaration;
    }
    
  public:
    inline cdk::sequence_node *instruction() {
      return _instruction;
    }

    /**
     * @param sp semantic processor visitor
     * @param level syntactic tree level
     */
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_block_node(this, level);
    }

  };

} // zu

#endif