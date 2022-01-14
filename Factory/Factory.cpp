#include "Factory.h"

IPieceModel *Factory::Create(const std::string &model, const int &y, const int &x, Color color) {
    if (model == "Checker") {
        //Создаем Subject (CheckerModel) с наблюдателем (CheckerView : Observer)
        auto *checker = new CheckerModel(y, x, Color(color));
        const auto observer = new CheckerView();
        checker->Attach(observer);
        return checker;

    } else if (model == "Queen") {
        //Создаем Subject (QueenModel) с наблюдателем (QueenView : Observer)
        auto *queen = new QueenModel(y, x, Color(color));
        const auto observer = new QueenView();
        queen->Attach(observer);
        return queen;
    }
    return nullptr;
}

