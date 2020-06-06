//
// Created by long on 30/05/2020.
//

#include "Observable.h"
IObserver::IObserver(Observable& subject) : subject(subject) {
    subject.attach(this);
}
IObserver::~IObserver() {
    subject.detach(this);
}
