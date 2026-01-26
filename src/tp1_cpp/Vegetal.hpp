
#pragma once

class Vegetal {
public:
    virtual ~Vegetal() = default;
    virtual void croissance() = 0;
    float getTaille() const;

protected:
    void setTaille(float taille);

private:
    float mTaille = 0.0f;
};