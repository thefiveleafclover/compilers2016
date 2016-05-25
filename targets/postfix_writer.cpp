// $Id: postfix_writer.cpp,v 1.21 2016/05/20 12:44:37 ist178929 Exp $ -*- c++ -*-
#include <string>
#include <sstream>
#include "targets/type_checker.h"
#include "targets/postfix_writer.h"
#include "ast/all.h"  // all.h is automatically generated





//---------------------------------------------------------------------------
//     THIS IS THE VISITOR'S DEFINITION
//---------------------------------------------------------------------------

void zu::postfix_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++) {
    node->node(i)->accept(this, lvl);
  }
}

//---------------------------------------------------------------------------

//TODO: A lot of stuff

void zu::postfix_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  _pf.INT(node->value()); // push an integer
}

void zu::postfix_writer::do_string_node(cdk::string_node * const node, int lvl) {
  int lbl1;

  /* generate the string */
  _pf.RODATA(); // strings are DATA readonly
  _pf.ALIGN(); // make sure we are aligned
  _pf.LABEL(mklbl(lbl1 = ++_lbl)); // give the string a name
  _pf.STR(node->value()); // output string characters

  /* leave the address on the stack */
  _pf.TEXT(); // return to the TEXT segment
  _pf.ADDR(mklbl(lbl1)); // the string to be printed
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->argument()->accept(this, lvl); // determine the value
  _pf.NEG(); // 2-complement
}
void zu::postfix_writer::do_not_node(zu::not_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->argument()->accept(this, lvl); // determine the value
  _pf.NOT(); // does this work?
}
void zu::postfix_writer::do_identity_node(zu::identity_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
        node->argument()->accept(this,lvl);
}
void zu::postfix_writer::do_address_node(zu::address_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
        node->argument()->accept(this,lvl);
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_or_node(zu::or_node * const node, int lvl) {  
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.OR();
}
void zu::postfix_writer::do_and_node(zu::and_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.AND();
    
}
void zu::postfix_writer::do_indexation_node(zu::indexation_node * const node, int lvl) {
  /*CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.INT(node->left()->type()->subtype()->size());
  _pf.MUL();
  _pf.ADD();*/
}
void zu::postfix_writer::do_add_node(cdk::add_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.ADD();
}
void zu::postfix_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.SUB();
}
void zu::postfix_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MUL();
}
void zu::postfix_writer::do_div_node(cdk::div_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.DIV();
}
void zu::postfix_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MOD();
}
void zu::postfix_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.LT();
}
void zu::postfix_writer::do_le_node(cdk::le_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.LE();
}
void zu::postfix_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.GE();
}
void zu::postfix_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.GT();
}
void zu::postfix_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.NE();
}
void zu::postfix_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.EQ();
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_rvalue_node(zu::rvalue_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->lvalue()->accept(this, lvl);
  _pf.LOAD(); //FIXME: depends on type size
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_lvalue_node(zu::lvalue_node * const node, int lvl) {
  //CHECK_TYPES(_compiler, _symtab, node);
  //node->accept(this,lvl);
   //CHECK_TYPES(_compiler, _symtab, node);
  // simplified generation: all variables are global
  //_pf.ADDR(node->value());
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_assignment_node(zu::assignment_node * const node, int lvl) {
 /* CHECK_TYPES(_compiler, _symtab, node);

  // DAVID: horrible hack!
  // (this is caused by Zu not having explicit variable declarations)
  const std::string &id = node->lvalue()->value();
  std::shared_ptr<zu::symbol> symbol = _symtab.find(id);
  if (symbol->value() == -1) {
    _pf.DATA(); // variables are all global and live in DATA
    _pf.ALIGN(); // make sure we are aligned
    _pf.LABEL(id); // name variable location
    _pf.CONST(0); // initialize it to 0 (zero)
    _pf.TEXT(); // return to the TEXT segment
    symbol->value(0);
  }

  node->rvalue()->accept(this, lvl); // determine the new value
  _pf.DUP();
  node->lvalue()->accept(this, lvl); // where to store the value
  _pf.STORE(); // store the value at address*/
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_function_node(zu::function_node * const node, int lvl) {
  /*// Note that Zu doesn't have functions. Thus, it doesn't need
  // a function node. However, it must start in the main function.
  // The ProgramNode (representing the whole program) doubles as a
  // main function node.

  // generate the main function (RTS mandates that its name be "_main")
  _pf.TEXT();
  _pf.ALIGN();
  _pf.GLOBAL("_main", _pf.FUNC());
  _pf.LABEL("_main");
  _pf.ENTER(0);  // Zu doesn't implement local variables

  node->statements()->accept(this, lvl);

  // end the main function
  _pf.INT(0);
  _pf.POP();
  _pf.LEAVE();
  _pf.RET();

  // these are just a few library function imports
  _pf.EXTERN("readi");
  _pf.EXTERN("printi");
  _pf.EXTERN("prints");
  _pf.EXTERN("println");
  _pf.EXTERN("breaki");
  _pf.EXTERN("continuei");
  _pf.EXTERN("returni");    */
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_break_node(zu::break_node * const node, int lvl) {
	//FIXME: Complete method
}

void zu::postfix_writer::do_continue_node(zu::continue_node * const node, int lvl) {
	//FIXME: Complete method
}

void zu::postfix_writer::do_return_node(zu::return_node * const node, int lvl) {
    CHECK_TYPES(_compiler, _symtab, node);
    //node->argument()->accept(this, lvl);
    /*if(_current_function == NULL) {
		// FIXME: EXTERMINATE
		std::cout << "WRONG! Cannot return if outside a function! *sigh*" << std::endl;
		return;
	}

	// Place return value on EAX (POP!)
	if(_current_function->type()->name() != ExpressionType::TYPE_VOID) {
		// this is stupid, but gcc was acting strange and i was lazy to find out why
		int return_offset = 0 - _current_function->type()->size();
		_pf.LOCV(return_offset); // push return variable value to stack
		_pf.POP(); // return value goes *POP*
	}
	// End function and return to previous context */
	_pf.LEAVE();
	_pf.RET();
}

void zu::postfix_writer::do_evaluation_node(zu::evaluation_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->argument()->accept(this, lvl); // determine the value
          _pf.EXTERN("printi");
        _pf.EXTERN("prints");
        _pf.EXTERN("println");
  if (node->argument()->type()->name() == basic_type::TYPE_INT) {
    _pf.TRASH(4); // delete the evaluated value
  }
  else if (node->argument()->type()->name() == basic_type::TYPE_STRING) {
    _pf.TRASH(4); // delete the evaluated value's address
  }
  else {
    std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
    exit(1);
  }
}

void zu::postfix_writer::do_print_node(zu::print_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->argument()->accept(this, lvl); // determine the value to print
  if (node->argument()->type()->name() == basic_type::TYPE_INT) {
    _pf.EXTERN("printi");
    _pf.CALL("printi");
    _pf.TRASH(4); // delete the printed value
  }
  if (node->argument()->type()->name() == basic_type::TYPE_STRING) {
    _pf.EXTERN("prints");
    _pf.CALL("prints");
    _pf.TRASH(4); // delete the printed value's address
  }
  if (node->argument()->type()->name() == basic_type::TYPE_DOUBLE) {
    _pf.EXTERN("printd");
    _pf.CALL("printd");
    _pf.TRASH(8); // delete the printed value's address
  }
    /*else {
    std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
    exit(1);
  }*/
  if (node->nl()){
    _pf.EXTERN("println");
    _pf.CALL("println"); // print a newline
  }
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_read_node(zu::read_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  _pf.CALL("readi");
  _pf.PUSH();
  node->accept(this, lvl);
  _pf.STORE();
}

//---------------------------------------------------------------------------

/*void zu::postfix_writer::do_while_node(zu::while_node * const node, int lvl) {
  int lbl1, lbl2;
  _pf.LABEL(mklbl(lbl1 = ++_lbl));
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl2 = ++_lbl));
  node->block()->accept(this, lvl + 2);
  _pf.JMP(mklbl(lbl1));
  _pf.LABEL(mklbl(lbl2));
}*/

void zu::postfix_writer::do_for_node(zu::for_node * const node, int lvl) {
	//FIXME: Complete method

}

void zu::postfix_writer::do_apply_node(zu::apply_node * const node, int lvl) {
  
}

//---------------------------------------------------------------------------


void zu::postfix_writer::do_if_node(zu::if_node * const node, int lvl) {
  int lbl1;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->block()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl1));
}

//---------------------------------------------------------------------------

void zu::postfix_writer::do_if_else_node(zu::if_else_node * const node, int lvl) {
  int lbl1, lbl2;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->thenblock()->accept(this, lvl + 2);
  _pf.JMP(mklbl(lbl2 = ++_lbl));
  _pf.LABEL(mklbl(lbl1));
  node->elseblock()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl1 = lbl2));
}


void zu::postfix_writer::do_zuidentifier_node(zu::zuidentifier_node * const node, int lvl) {
	  CHECK_TYPES(_compiler, _symtab, node);
          node->accept(this,lvl);
          CHECK_TYPES(_compiler, _symtab, node);
  // simplified generation: all variables are global
          _pf.ADDR(node->id());
}

void zu::postfix_writer::do_identifier_node(cdk::identifier_node * const node, int lvl) {
	//FIXME: Complete method
}

void zu::postfix_writer::do_block_node(zu::block_node * const node, int lvl) {
        CHECK_TYPES(_compiler, _symtab, node);	
        _symtab.push();
        if(node->declaration() != NULL){
            node->declaration()->accept(this, lvl);
        }
        if(node->instruction() != NULL){
            node->instruction()->accept(this, lvl);
        }
        _symtab.pop();
}

void zu::postfix_writer::do_memalloc_node(zu::memalloc_node * const node, int lvl) {
	//FIXME: Complete method
}

void zu::postfix_writer::do_funcall_node(zu::funcall_node * const node, int lvl) {
	//FIXME: Complete method
}

void zu::postfix_writer::do_functionDeclaration_node(zu::functionDeclaration_node * const node, int lvl) {
	
}

void zu::postfix_writer::do_functionDefinition_node(zu::functionDefinition_node * const node, int lvl) {
        _pf.EXTERN("readi");
        _pf.EXTERN("breaki");
        _pf.EXTERN("continuei");
        _pf.EXTERN("returni");
        _pf.EXTERN("prints");
        _pf.EXTERN("println");
        _pf.EXTERN("printi");
        _pf.EXTERN("printd");
	std::string name = "";
        if(node->identifier()->id() == "zu") { name="_main"; }
        if(node->identifier()->id() == "_main") { name="zu"; }
        //else { name=node->identifier()->id(); }
        _pf.TEXT();
        _pf.ALIGN();
        _pf.GLOBAL("_main", _pf.FUNC());
        _pf.LABEL("_main");
        _pf.ENTER(0);
        /*stack_counter sc;
         * node->accept(%sc, lvl);
         * size_t localsize = sc.get_size();
         */
       /* size_t retsize = node->type()->size();
        _pf.ENTER(retsize); //+localsize?
        if(node->literal() != nullptr){
            node->literal()->accept(this,lvl+2);
            _pf.LOCA(-retsize);
        } 
        else if(node->type()->name() == basic_type::TYPE_INT){
            _pf.LOCA(4);
        }*/        
        node->instructions()->accept(this,lvl);
        //_pf.LOCV(-retsize);
        _pf.INT(0);
        _pf.POP();
        _pf.LEAVE();
        _pf.RET();
}

void zu::postfix_writer::do_variableDeclaration_node(zu::variableDeclaration_node * const node, int lvl) {
	//FIXME: Complete method
}

void zu::postfix_writer::do_variableDefinition_node(zu::variableDefinition_node * const node, int lvl) {
	//FIXME: Complete method
}

void zu::postfix_writer::do_expressionAsInstruction_node(zu::expressionAsInstruction_node * const node, int lvl) {
	//FIXME: Complete method
}
