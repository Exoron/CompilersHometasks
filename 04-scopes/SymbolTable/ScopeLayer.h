#pragma once

#include <memory>
#include <unordered_map>
#include <vector>

#include <Objects/Object.h>
#include <SymbolTable/Symbol.h>

class ScopeLayer {
 public:
  explicit ScopeLayer(ScopeLayer* parent);
  ScopeLayer();
  void DeclareVariable(Symbol symbol);
  void Put(Symbol symbol, std::shared_ptr<Object> value);
  std::shared_ptr<Object> Get(Symbol symbol);
  bool Has(Symbol symbol);

  void AddChild(ScopeLayer* child);
  // void AttachParent();

  ScopeLayer* GetChild(size_t index);
  ScopeLayer* GetParent() const;
 private:
  std::unordered_map<Symbol, std::shared_ptr<Object>> values_;
  std::vector<Symbol> symbols_;
  ScopeLayer* parent_;
  std::vector<ScopeLayer*> children_;
};
