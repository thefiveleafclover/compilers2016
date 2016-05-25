#ifndef __ZU_FUNCTIONDEFINITIONNODE_H__
#define __ZU_FUNCTIONDEFINITIONNODE_H__

#include <cdk/ast/basic_node.h>
#include <cdk/basic_type.h>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/nil_node.h>
#include <ast/functionDeclaration_node.h>
#include <cdk/ast/expression_node.h>


namespace zu {

    /**
     * Class for describing function definition nodes.
     */
    class functionDefinition_node: public zu::functionDeclaration_node {
		cdk::expression_node *_literal;
		cdk::basic_node *_instr;

    public:
        
      inline functionDefinition_node(int lineno, basic_type *type, bool ispublic, bool gl, zuidentifier_node *id, cdk::sequence_node *args, cdk::expression_node *literal, cdk::basic_node *instructions) :
          zu::functionDeclaration_node(lineno, type, ispublic, gl, id, args), _literal(literal), _instr(instructions) {
      }

		

    public:
      inline cdk::basic_node *instructions() {
        return _instr;
      }
      
      inline cdk::expression_node *literal() {
        return _literal;
      }
      
	
      void accept(basic_ast_visitor *sp, int level) {
        sp->do_functionDefinition_node(this, level);
      }

    };

} // namespace zu

#endif 
