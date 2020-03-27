#include <cstdlib>
#include <climits>
#include "SLList.hpp"

using namespace std;

SLList * const SLList::NIL = new SLList(0, NULL);

SLList::SLList(int i, SLList *n) {
	f_ = i;
	r_ = n; 
}

int SLList::first() {
	return f_;
}

SLList *SLList::rest() {
	return r_;
}

void SLList::setFirst(int i) {
	f_ = i;
}

void SLList::setRest(SLList *n) {
	r_ = n;
}

int SLList::nth(unsigned int i) {
	if (i == 0) {
		return f_;
	} else {
		return r_ -> nth(i-1);
	}
}

SLList *SLList::nthRest(unsigned int i) {
	if (i == 0) {
		return this;
	} else {
		return r_ -> nthRest(i-1); 
	}
}

unsigned int SLList::length() {
	return lengthAux(0);
}

unsigned int SLList::lengthAux(int i) {
	if (r_ == NULL) {
		return i;
	}
	else {
		return r_ -> lengthAux(i + 1);
	}
}

SLList *SLList::remove(int i) {
	if (this == NIL) {
		return NIL;
	}
	else if (i == f_) {
		return r_ -> remove(i);
	}
	else {	
		return new SLList(f_, r_ -> remove(i));
	}
}

SLList *SLList::reverse() {
	if (this == NIL) {
		return NIL;
	}
	else if (r_ == NIL) {
		return new SLList(f_, NIL);
	}
	else {
		SLList *o = r_ -> reverse();
		SLList *n = new SLList(f_, NIL);
		o -> append(n);
		return o;
	}
}

SLList *SLList::append(SLList *other){
	if (r_ == NIL) {
		setRest(other);
	}
	else {
		r_ -> append(other);
	}
} 

int SLList::sum() {
	SLList *a = this;
	if (a == NIL) {
		return 0;
	}
	else {
		return f_ + (a -> r_ -> sum());
	}
}

SLList *SLList::sublist(int start, int end) {
    if (start == end) {
        return NIL;
    }
    else {
        return new SLList(nth(start), sublist(start+1, end));
    }

}

SLList *SLList::merge(SLList *b) {
    if (this == NIL) {
        return b;
    }
    else if (b == NIL) {
        return this;
    }
    else if (f_ <= b -> first()) {
        return new SLList(first(), b -> merge(rest()));
    }
    else {
        return new SLList(b->first(), merge(b->rest()));
   }
}

SLList *SLList::mergesort() {
    int sl = this -> length();

    if (sl <= 1) {
        return this;
    }
    else {
        int mid = sl/2;
        SLList *left = sublist(0, mid) -> mergesort();
        SLList *right = sublist(mid, sl) -> mergesort();
        return left -> merge(right);
    }
}
