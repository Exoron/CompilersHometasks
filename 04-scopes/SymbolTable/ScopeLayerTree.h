#pragma once

class ScopeLayer;

class ScopeLayerTree {
 public:
  explicit ScopeLayerTree(ScopeLayer* root);
 public:
  ScopeLayer* root_;
};
