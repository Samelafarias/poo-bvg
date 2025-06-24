#ifndef FILTRO_H
#define FILTRO_H

#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

template <typename T>
class Filtro {
private:
    std::vector<T> elementos;

public:
    void adicionarElemento(const T& elemento) {
        elementos.push_back(elemento);
    }

    std::vector<T> filtrarPorCondicao(std::function<bool(const T&)> condicao) const {
        std::vector<T> resultados;
        for (const auto& elemento : elementos) {
            if (condicao(elemento)) {
                resultados.push_back(elemento);
            }
        }
        return resultados;
    }

    void imprimirTodos(std::function<void(const T&)> acao) const {
        for (const auto& elemento : elementos) {
            acao(elemento);
        }
    }

    const std::vector<T>& getElementos() const {
        return elementos;
    }

    void limparElementos() {
        elementos.clear();
    }

    void ordenar(std::function<bool(const T&, const T&)> comparador) {
        std::sort(elementos.begin(), elementos.end(), comparador);
    }
};

#endif