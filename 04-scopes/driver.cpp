#include "driver.hh"
#include "parser.hh"
#include <Visitors/Interpreter.h>
#include <Visitors/PrintVisitor.h>
#include <Visitors/SymbolTreeVisitor.h>


Driver::Driver() :
    trace_parsing(false),
    trace_scanning(false),
    scanner(*this), parser(scanner, *this) {}

Driver::~Driver() {
  if(program != nullptr) {
    delete program;
    program = nullptr;
  }
}

int Driver::parse(const std::string& f) {
  file = f;
  location.initialize(&file);
  scan_begin();
  parser.set_debug_level(trace_parsing);
  int res = parser();
  scan_end();
  return res;
}

void Driver::scan_begin() {
  scanner.set_debug(trace_scanning);
  if (file.empty () || file == "-") {
  } else {
    stream.open(file);
    std::cout << file << std::endl;
    scanner.yyrestart(&stream);
  }
}

void Driver::scan_end()
{
  stream.close();
}

void Driver::Run() {
  if(program == nullptr) {
    std::cout << "No program" << std::endl;
    return;
  }

  SymbolTreeVisitor visitor;
  visitor.Visit(program);

  std::cout << "Symbol tree built" << std::endl << std::endl;

  std::cout << "The program starts" << std::endl << std::endl;

  ScopeLayer* root = visitor.GetRoot();
  Interpreter interpreter(root);
  interpreter.Visit(program);
}

void Driver::PrintTree(const std::string & filename) {
  if(program != nullptr) {
    PrintVisitor printer(filename);
    program->Accept(&printer);
  }
}
