#include "ScopeLayer.h"

#include <Objects/UninitObject.h>
#include <SymbolTable/Symbol.h>

#include <iostream>

ScopeLayer::ScopeLayer(ScopeLayer* parent) : parent_(parent) {
  parent_->AddChild(this);
}

ScopeLayer::ScopeLayer() : parent_(nullptr) {}

ScopeLayer::~ScopeLayer() {
  for(auto child: children_) {
    delete child;
  }
}

void ScopeLayer::DeclareVariable(Symbol symbol) {
  if (values_.find(symbol) != values_.end()) {
    throw std::runtime_error("Variable `" + symbol.GetName() +
                             "` has already been declared in "
                             "this scope");
  }

  values_[symbol] = std::make_shared<UninitObject>();
  // offsets_[symbol] = symbols_.size();
  symbols_.push_back(symbol);
}

void ScopeLayer::Put(Symbol symbol, std::shared_ptr<Object> value) {
  ScopeLayer* current_layer = this;

  while (!current_layer->Has(symbol) && current_layer->parent_ != nullptr) {
    current_layer = current_layer->parent_;
  }
  if (current_layer->Has(symbol)) {
    current_layer->values_.find(symbol)->second = value;
  } else {
    throw std::runtime_error("Variable `" + symbol.GetName() +
                             "` is not declared");
  }
}

bool ScopeLayer::Has(Symbol symbol) {
  return values_.find(symbol) != values_.end();
}

std::shared_ptr<Object> ScopeLayer::Get(Symbol symbol) {
  ScopeLayer* current_layer = this;

  while (!current_layer->Has(symbol) && current_layer->parent_ != nullptr) {
    current_layer = current_layer->parent_;
  }
  if (current_layer->Has(symbol)) {
    return current_layer->values_.find(symbol)->second;
  } else {
    throw std::runtime_error("Variable not declared");
  }
}

ScopeLayer* ScopeLayer::GetChild(size_t index) { return children_[index]; }

void ScopeLayer::AddChild(ScopeLayer* child) { children_.push_back(child); }

ScopeLayer* ScopeLayer::GetParent() const { return parent_; }