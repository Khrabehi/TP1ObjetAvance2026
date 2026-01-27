
#pragma once
class Vegetal 
{
public:
  Vegetal();
  virtual ~Vegetal() = default;
  float getTaille() const; 
  virtual void croissance() = 0;
private:
  float mTaille;
protected:
  void setTaille(float t);
};