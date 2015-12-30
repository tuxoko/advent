#!/usr/bin/env python3
import sys

def opd(o):
    if o.isnumeric():
        return '((unsigned short)%s)' % o
    else:
        return '%s(t)' % o.upper()

def do_header(ll, end=''):
    print('unsigned short %s(int t)%s' % (ll[-1].upper(), end))

def do_static():
    print('static unsigned short ss[2] = {};')
    print('if (ss[t] != 0) return ss[t];')

def do_return(expr):
    print('return ss[t]=%s;' % expr)

def do_func(ret):
    do_header(ll)
    print('{')
    do_static()
    do_return(ret)
    print('}')

def do_assign(ll):
    do_header(ll)
    print('{')
    do_static()
    if ll[len(ll)-1] == 'b':
        print('if (t) return ss[t]=A(0);\nelse ', end='')
    do_return(opd(ll[0]))
    print('}')

def do_not(ll):
    do_func('~'+opd(ll[1]))

def do_and_or(ll):
    op = '&' if ll[1] == 'AND' else '|'
    do_func(opd(ll[0])+op+opd(ll[2]))

def do_shift(ll):
    op = '<<' if ll[1] == 'LSHIFT' else '>>'
    do_func(opd(ll[0])+op+opd(ll[2]))

lines = [ line for line in sys.stdin ]

for line in lines:
    ll = line.strip().split(' ')
    do_header(ll, ';')

for line in lines:
    ll = line.strip().split(' ')
    if ll[1] == '->':
        do_assign(ll)
    elif ll[0] == 'NOT':
        do_not(ll)
    elif ll[1] == 'AND' or ll[1] == 'OR':
        do_and_or(ll)
    elif ll[1] == 'RSHIFT' or ll[1] == 'LSHIFT':
        do_shift(ll)

print('#include<stdio.h>')
print('int main(void){')
print('printf("%hu\\n%hu\\n", A(0), A(1));')
print('return 0;}')
