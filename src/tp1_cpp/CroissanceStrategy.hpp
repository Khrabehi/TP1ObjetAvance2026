#pragma once

class CroissanceStrategy {
public:
    virtual ~CroissanceStrategy() = default;
    virtual float increment() const = 0;
};

class CroissanceConstante : public CroissanceStrategy {
public:
    explicit CroissanceConstante(float delta = 1.f) : mDelta(delta) {}
    float increment() const override { return mDelta; }
private:
    float mDelta;
};

class CroissanceDormance : public CroissanceStrategy {
public:
    float increment() const override { return 0.f; }
};

class CroissancePrintaniere : public CroissanceStrategy {
public:
    float increment() const override { return 2.f; }
};

class CroissanceEstivale : public CroissanceStrategy {
public:
    float increment() const override { return 1.5f; }
};

class CroissanceSecheresse : public CroissanceStrategy {
public:
    float increment() const override { return 0.f; }
};