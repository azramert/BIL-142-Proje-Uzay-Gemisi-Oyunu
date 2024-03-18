#include "functions.h"
#include "gemi.h"
#include <memory>
#include "gemiSecimi.h"

int main() {
    std::shared_ptr<Gemi> secilenGemi = gemiSecimi();
    eventSecici(secilenGemi);
    return 0;
}
