#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;

//Struct para o nome e preço dos produtos
struct Produto {
    string nome;
    float preco;
};

int main() {
    
    // vetor onde vai armazenar o nome do produto e seu preço, onde <Produto> é a struct e 
    //"bebidas" é para definir o vetor que sera sobre bebidas, a logica é  a mesma para novos vetores.
    
    vector<Produto> carrinho; // vetor para o carrinho
    
    vector<Produto> bebidas = {
        {"CocaCola", 10},
        {"Pepsi", 8},
        {"Sprite", 7},
        {"Água mineral", 6},
        {"Fanta", 6},
        {"Dolly", 5},
    };
    vector<Produto> roupas = {
        {"Camisa Gucci branca", 304},
        {"Calça Cargo preta", 250},
        {"Calça Jeans clara", 120},
        {"Botas de couro", 240},
        {"Casaco de couro veludo", 300},
        {"tenis allstar preto cano curto", 200},
    };
    vector<Produto> acessorio ={
        {"Boné preto NY", 120},
        {"Relogio rolex prata", 450},
        {"Anel de ouro 18k", 2000},
        {"Meia longa Adidas", 140},
        {"Pulseira GUCCI", 300},
        {"Colar de perolas", 200},
                            
    };
    vector<Produto> produtoLimpeza ={
        {"Sabão em pó omo", 20},
        {"Detergente YPE", 3},
        {"Amaciante Downy", 29},
        {"Agua sanitaria", 10},
        {"Sabão barra", 8},
        {"Desinfetante Sanol", 20}
    };

    //map funciona como se fosse um dicionario, ele vai organizar por pares.
    //map<int (tipo da variavel de seleção), pair(vai organizar em 2 pares), < os tipos deles> e depois o nome desse dicionario.
    // map<int, pair <tipo1, tipo2>> nome = {}
    
    map<int, pair<float, string>> idiomas = {
        {1, {0.69, "¥" }},
        {2, {0.35, "$" }},
        {3, {0.20, "€" }},
        {4, {0.30, "د. إ." }}
    };
    
    int escolhaProduto;
    int produto;
    int lingua;
    

    do {
        float valorCompra=0;
        
        cout << "\nEscolha o seu idioma:" << endl;
        cout << "[1]- 中文 [Chinês]\n[2]- English\n[3]- Español\n[4]- عربي [Árabe]\n[0]- Sair" << endl;
        cout << ">> ";
        cin >> lingua;

        switch (lingua) {
            case 1:
            
                do {
                    cout << "\n欢迎您，您想选择哪个类别？" << endl;
                    //cout << "[1]- Bebida\n[2]- [Roupas]\n[3]- Acessorios\n[4]- Produto de limpeza\n[5]- Mostrar carrinho\n[0]- Voltar" << endl;
                    cout << "[1]- 饮料 \n[2]- 服装\n[3]- 饰品\n[4]- 清洁用品\n[5]- 显示购物车\n[0]- 返回" << endl;

                    cout << ">> ";
                    cin >> produto;
                    
                    switch (produto) {
                        case 1:
                        
                            do{
                            cout << "\n选择饮料：" << endl;
                            
                            //for onde ele vai fazer o loop baseado no tamanho do vector bebidas
                            for (int i = 0; i < bebidas.size(); i++) {
                                
                                //fixed serve para arredondar o numero para a quantidade de numeros no setprecision, setprecision(2) serve para limitar a casa de numero real em 2
                                //idiomas[lingua].first esta pegando a map idiomas e seleciona dentro do map baseado na escolha da lingua e pega o primeiro tipo no par
                                //idiomas[lingua].second aqui é a mesma coisa que o de cima porem pega o segundo tipo
                                
                                cout << "[" << i+1 << "] " << bebidas[i].nome << " - " << fixed <<setprecision(2) << bebidas[i].preco / idiomas[lingua].first << idiomas[lingua].second << endl;
                            }
                            cout << "[0]- 返回" << endl;
                            cout << ">> ";
                            
                            cin >> escolhaProduto;
                            
                            // um if onde a escolha do produto tem que ser maior que 0 e ser menor/igual que o tamanho das bebidas
                            // o -1 no valorCompra é para igualar ao vector
                            if (escolhaProduto > 0 && escolhaProduto <= bebidas.size()) {
                                valorCompra += (bebidas[escolhaProduto - 1].preco / idiomas[lingua].first);
                                //push_back() ele ira adicionar o produto escolhido no vector "carrinho" dinamicamente.
                                carrinho.push_back(bebidas[escolhaProduto - 1]);
                                cout << "\n" << bebidas[escolhaProduto - 1].nome << " 已添加到购物车。" << endl;
                            }
                            }while(escolhaProduto != 0);
                            break;
                            
                        case 2:
                            
                            do{
                                
                                cout << "\n选择服装：" << endl;
                                for (int i = 0; i < roupas.size(); i++){
                                    cout << "["<< i+1 << "] "<< roupas[i].nome << " - " << fixed << setprecision(2) << roupas[i].preco / idiomas[lingua].first << idiomas[lingua].second << endl;
                                }
                                
                            cout << "[0]- 返回" << endl;
                            cout << ">> ";
                            
                            cin >> escolhaProduto;
                            
                            if(escolhaProduto > 0 && escolhaProduto <= roupas.size()){
                                valorCompra += (roupas[escolhaProduto - 1].preco / idiomas[lingua].first);
                                carrinho.push_back(roupas[escolhaProduto - 1]);
                                cout << "\n" << roupas[escolhaProduto - 1].nome << " 已添加到购物车。" << endl;
                            }
                            
                            }while(escolhaProduto != 0);
                            break;
                            
                        case 3:
                            do{
                                cout << "\n选择配饰：" << endl;
                                
                                for (int i = 0; i < acessorio.size(); i++){
                                    cout << "["<< i+1 << "] "<< acessorio[i].nome << " - " << fixed << setprecision(2) << acessorio[i].preco / idiomas[lingua].first << idiomas[lingua].second << endl;
                                }
                                
                                cout << "[0]- 返回" << endl;
                                cout << ">> ";
                            
                                cin >> escolhaProduto;
                            
                                if(escolhaProduto > 0 && escolhaProduto <= acessorio.size()){
                                    valorCompra += (acessorio[escolhaProduto - 1].preco / idiomas[lingua].first);
                                    carrinho.push_back(acessorio[escolhaProduto - 1]);
                                    cout << "\n" << acessorio[escolhaProduto - 1].nome << " 已添加到购物车。" << endl;
                                }   
                            
                            }while(escolhaProduto != 0);
                            break;
                            
                        case 4:
                            
                            do{
                               cout << "\n选择清洁用品：" << endl;
                                
                                for (int i = 0; i < produtoLimpeza.size(); i++){
                                    cout << "[" << i+1 << "]" << produtoLimpeza[i].nome << " - " << fixed << setprecision(2) << produtoLimpeza[i].preco /idiomas[lingua].first << idiomas[lingua].second << endl;
                                }
                                
                                cout << "[0]- 返回" << endl;
                                cout << ">> ";
                                
                                cin >> escolhaProduto;
                                
                                if (escolhaProduto > 0 && escolhaProduto <= produtoLimpeza.size()){
                                    valorCompra += (produtoLimpeza[escolhaProduto - 1].preco / idiomas[lingua].first);
                                    carrinho.push_back(produtoLimpeza[escolhaProduto - 1]);
                                    cout << "\n" << produtoLimpeza[escolhaProduto - 1].nome << " 已添加到购物车。" << endl;
                                }
                            }while(escolhaProduto != 0);
                            break;
                            
                        case 5:
                        
                        //for (constante Tipo& variavel : vector) {}
                        // auto = irá verificar automaticamente que variavel ela é
                        //const = define que será constante as variaveis e nao poderão ser alteradas 
                        // & é para indicar a referencia, assim alterando as variaveis no vector, caso nao use o "&" ele ira alterar a variavel local,
                        //depois do loop terminar, os dados nao ficam salvos dentro do vector, pois foi alterado localmente e não no escopo global.
                        
                            cout << "\n您的购物车包含以下物品：" << endl;
                            for(const auto & item : carrinho){
                                cout<< item.nome << " - " << fixed <<setprecision(2) << item.preco / idiomas[lingua].first << idiomas[lingua].second << endl;
                                
                            }
                            cout <<"\n总价： "<<valorCompra<<idiomas[lingua].second << endl;
                            break;
                    }
                } while (produto != 0);
                break;

            case 2:

                do {
                    cout << "\nWelcome, which category do you want to choose？" << endl;
                    cout << "[1]- Drinks\n[2]- Clothing\n[3]- Accessories\n[4]- Cleaning product\n[5]- View cart\n[0]- Back" << endl;
                    cout << ">> ";
                    cin >> produto;
                    
                    switch (produto) {
                        case 1:
                        
                            do{
                            cout << "\nChoose your drink" << endl;
                            
                            for (int i = 0; i < bebidas.size(); i++) {
                                
                                cout << "[" << i+1 << "] " << bebidas[i].nome << " - " << fixed <<setprecision(2) << bebidas[i].preco / idiomas[lingua].first << idiomas[lingua].second << endl;
                            }
                            cout << "[0] Back" << endl;
                            cout << ">> ";
                            
                            cin >> escolhaProduto;

                            if (escolhaProduto > 0 && escolhaProduto <= bebidas.size()) {
                                valorCompra += (bebidas[escolhaProduto - 1].preco / idiomas[lingua].first);
                             
                                carrinho.push_back(bebidas[escolhaProduto - 1]);
                                cout << "\n" << bebidas[escolhaProduto - 1].nome << " Added to cart." << endl;
                            }
                            }while(escolhaProduto != 0);
                            break;
                            
                        case 2:
                            
                            do{
                                
                                cout << "\nChoose the clothes: " << endl;
                                for (int i = 0; i < roupas.size(); i++){
                                    cout << "["<< i+1 << "] "<< roupas[i].nome << " - " << fixed << setprecision(2) << roupas[i].preco / idiomas[lingua].first << idiomas[lingua].second << endl;
                                }
                                
                            cout << "[0] Back" << endl;
                            cout << ">> ";
                            
                            cin >> escolhaProduto;
                            
                            if(escolhaProduto > 0 && escolhaProduto <= roupas.size()){
                                valorCompra += (roupas[escolhaProduto - 1].preco / idiomas[lingua].first);
                                carrinho.push_back(roupas[escolhaProduto - 1]);
                                cout << "\n" << roupas[escolhaProduto - 1].nome << " Added to cart." << endl;
                            }
                            
                            }while(escolhaProduto != 0);
                            break;
                            
                        case 3:
                            do{
                                cout << "\nChoose the accessories:" << endl;
                                
                                for (int i = 0; i < acessorio.size(); i++){
                                    cout << "["<< i+1 << "] "<< acessorio[i].nome << " - " << fixed << setprecision(2) << acessorio[i].preco / idiomas[lingua].first << idiomas[lingua].second << endl;
                                }
                                
                                cout << "[0] Back" << endl;
                                cout << ">> ";
                            
                                cin >> escolhaProduto;
                            
                                if(escolhaProduto > 0 && escolhaProduto <= acessorio.size()){
                                    valorCompra += (acessorio[escolhaProduto - 1].preco / idiomas[lingua].first);
                                    carrinho.push_back(acessorio[escolhaProduto - 1]);
                                    cout << "\n" << acessorio[escolhaProduto - 1].nome << " Added to cart." << endl;
                                }   
                            
                            }while(escolhaProduto != 0);
                            break;
                            
                        case 4:
                            
                            do{
                                cout << "\n Choose the cleaning products" << endl;
                                
                                for (int i = 0; i < produtoLimpeza.size(); i++){
                                    cout << "[" << i+1 << "]" << produtoLimpeza[i].nome << " - " << fixed << setprecision(2) << produtoLimpeza[i].preco /idiomas[lingua].first << idiomas[lingua].second << endl;
                                }
                                
                                cout << "[0] Back" << endl;
                                cout << ">> ";
                                
                                cin >> escolhaProduto;
                                
                                if (escolhaProduto > 0 && escolhaProduto <= produtoLimpeza.size()){
                                    valorCompra += (produtoLimpeza[escolhaProduto - 1].preco / idiomas[lingua].first);
                                    carrinho.push_back(produtoLimpeza[escolhaProduto - 1]);
                                    cout << "\n" << produtoLimpeza[escolhaProduto - 1].nome << " Added to cart." << endl;
                                }
                            }while(escolhaProduto != 0);
                            break;
                            
                        case 5:
       
                            cout<<"\nIn your cart, you have the following items:" << endl;
                            for(const auto & item : carrinho){
                                cout<< item.nome << " - " << fixed <<setprecision(2) << item.preco / idiomas[lingua].first << idiomas[lingua].second << endl;
                                
                            }
                            cout <<"\nTotal price: "<<valorCompra<<idiomas[lingua].second<<endl;
                            break;
                    }
                } while (produto != 0);
                break;

            case 3:
                do {
                    cout << "\nBienvenido, ¿qué categoría desea elegir?" << endl;
                    cout << "[1]- Bebidas\n[2]- Ropa\n[3]- Accesorios\n[4]- Producto de limpieza\n[5]- Ver carrito\n[0]- Volver" << endl;
                    cout << ">> ";
                    cin >> produto;
                
                    switch (produto) {
                        case 1:
                            do {
                                cout << "\nElija su bebida" << endl;
                                for (int i = 0; i < bebidas.size(); i++) {
                                    cout << "[" << i+1 << "] " << bebidas[i].nome << " - " << fixed << setprecision(2) << bebidas[i].preco / idiomas[lingua].first << idiomas[lingua].second << endl;
                                }
                                cout << "[0] Volver" << endl;
                                cout << ">> ";
                                cin >> escolhaProduto;
                
                                if (escolhaProduto > 0 && escolhaProduto <= bebidas.size()) {
                                    valorCompra += (bebidas[escolhaProduto - 1].preco / idiomas[lingua].first);
                                    carrinho.push_back(bebidas[escolhaProduto - 1]);
                                    cout << "\n" << bebidas[escolhaProduto - 1].nome << " Agregado al carrito." << endl;
                                }
                            } while (escolhaProduto != 0);
                            break;
                
                        case 2:
                            do {
                                cout << "\nElija la ropa:" << endl;
                                for (int i = 0; i < roupas.size(); i++) {
                                    cout << "[" << i+1 << "] " << roupas[i].nome << " - " << fixed << setprecision(2) << roupas[i].preco / idiomas[lingua].first << idiomas[lingua].second << endl;
                                }
                                cout << "[0] Volver" << endl;
                                cout << ">> ";
                                cin >> escolhaProduto;
                
                                if (escolhaProduto > 0 && escolhaProduto <= roupas.size()) {
                                    valorCompra += (roupas[escolhaProduto - 1].preco / idiomas[lingua].first);
                                    carrinho.push_back(roupas[escolhaProduto - 1]);
                                    cout << "\n" << roupas[escolhaProduto - 1].nome << " Agregado al carrito." << endl;
                                }
                            } while (escolhaProduto != 0);
                            break;
                
                        case 3:
                            do {
                                cout << "\nElija los accesorios:" << endl;
                                for (int i = 0; i < acessorio.size(); i++) {
                                    cout << "[" << i+1 << "] " << acessorio[i].nome << " - " << fixed << setprecision(2) << acessorio[i].preco / idiomas[lingua].first << idiomas[lingua].second << endl;
                                }
                                cout << "[0] Volver" << endl;
                                cout << ">> ";
                                cin >> escolhaProduto;
                
                                if (escolhaProduto > 0 && escolhaProduto <= acessorio.size()) {
                                    valorCompra += (acessorio[escolhaProduto - 1].preco / idiomas[lingua].first);
                                    carrinho.push_back(acessorio[escolhaProduto - 1]);
                                    cout << "\n" << acessorio[escolhaProduto - 1].nome << " Agregado al carrito." << endl;
                                }
                            } while (escolhaProduto != 0);
                            break;
                
                        case 4:
                            do {
                                cout << "\nElija los productos de limpieza:" << endl;
                                
                                for (int i = 0; i < produtoLimpeza.size(); i++) {
                                    cout << "[" << i+1 << "] " << produtoLimpeza[i].nome << " - " << fixed << setprecision(2) << produtoLimpeza[i].preco / idiomas[lingua].first << idiomas[lingua].second << endl;
                                }
                                
                                cout << "[0] Volver" << endl;
                                cout << ">> ";
                                cin >> escolhaProduto;
                
                                if (escolhaProduto > 0 && escolhaProduto <= produtoLimpeza.size()) {
                                    valorCompra += (produtoLimpeza[escolhaProduto - 1].preco / idiomas[lingua].first);
                                    carrinho.push_back(produtoLimpeza[escolhaProduto - 1]);
                                    cout << "\n" << produtoLimpeza[escolhaProduto - 1].nome << " Agregado al carrito." << endl;
                                }
                            } while (escolhaProduto != 0);
                            
                            break;
                
                        case 5:
                            cout<<"\nEn su carrito, tiene los siguientes artículos:" << endl;
                            for(const auto & item : carrinho){
                                cout<< item.nome << " - " << fixed <<setprecision(2) << item.preco / idiomas[lingua].first << idiomas[lingua].second << endl;
                            }
                            cout <<"\npreco total: "<<valorCompra<<idiomas[lingua].second<<endl;
                            break;
                    }
                } while (produto != 0);
                break;
                
            case 4:
                do {
                    
                    cout << "\nأهلاً بك، أي فئة ترغب في اختيارها؟" << endl;
                    cout << "[1]- المشروبات\n[2]- الملابس\n[3]- الاكسسوارات\n[4]- منتج التنظيف\n[5]- عرض العربة\n[0]- الرجوع" << endl;
                    cout << ">> ";
                    cin >> produto;
                
                    switch (produto) {
                        case 1:
                            do {
                                cout << "\nاختر مشروبك" << endl;
                                for (int i = 0; i < bebidas.size(); i++) {
                                    cout << "[" << i+1 << "] " << bebidas[i].nome << " - " << fixed << setprecision(2) << bebidas[i].preco / idiomas[lingua].first << idiomas[lingua].second << endl;
                                }
                                cout << "[0] الرجوع" << endl;
                                cout << ">> ";
                                cin >> escolhaProduto;
                
                                if (escolhaProduto > 0 && escolhaProduto <= bebidas.size()) {
                                    valorCompra += (bebidas[escolhaProduto - 1].preco / idiomas[lingua].first);
                                    carrinho.push_back(bebidas[escolhaProduto - 1]);
                                    cout << "\n" << bebidas[escolhaProduto - 1].nome << " تمت إضافته إلى العربة." << endl;
                                }
                            } while (escolhaProduto != 0);
                            break;
                
                        case 2:
                            do {
                                cout << "\nاختر الملابس:" << endl;
                                for (int i = 0; i < roupas.size(); i++) {
                                    cout << "[" << i+1 << "] " << roupas[i].nome << " - " << fixed << setprecision(2) << roupas[i].preco / idiomas[lingua].first << idiomas[lingua].second << endl;
                                }
                                cout << "[0] الرجوع" << endl;
                                cout << ">> ";
                                cin >> escolhaProduto;
                
                                if (escolhaProduto > 0 && escolhaProduto <= roupas.size()) {
                                    valorCompra += (roupas[escolhaProduto - 1].preco / idiomas[lingua].first);
                                    carrinho.push_back(roupas[escolhaProduto - 1]);
                                    cout << "\n" << roupas[escolhaProduto - 1].nome << " تمت إضافته إلى العربة." << endl;
                                }
                            } while (escolhaProduto != 0);
                            break;
                
                        case 3:
                            do {
                                cout << "\nاختر الاكسسوارات:" << endl;
                                for (int i = 0; i < acessorio.size(); i++) {
                                    cout << "[" << i+1 << "] " << acessorio[i].nome << " - " << fixed << setprecision(2) << acessorio[i].preco / idiomas[lingua].first << idiomas[lingua].second << endl;
                                }
                                cout << "[0] الرجوع" << endl;
                                cout << ">> ";
                                cin >> escolhaProduto;
                
                                if (escolhaProduto > 0 && escolhaProduto <= acessorio.size()) {
                                    valorCompra += (acessorio[escolhaProduto - 1].preco / idiomas[lingua].first);
                                    carrinho.push_back(acessorio[escolhaProduto - 1]);
                                    cout << "\n" << acessorio[escolhaProduto - 1].nome << " تمت إضافته إلى العربة." << endl;
                                }
                            } while (escolhaProduto != 0);
                            break;
                
                        case 4:
                            do {
                                cout << "\nاختر منتجات التنظيف:" << endl;
                                for (int i = 0; i < produtoLimpeza.size(); i++) {
                                    cout << "[" << i+1 << "] " << produtoLimpeza[i].nome << " - " << fixed << setprecision(2) << produtoLimpeza[i].preco / idiomas[lingua].first << idiomas[lingua].second << endl;
                                }
                                cout << "[0] الرجوع" << endl;
                                cout << ">> ";
                                cin >> escolhaProduto;
                
                                if (escolhaProduto > 0 && escolhaProduto <= produtoLimpeza.size()) {
                                    valorCompra += (produtoLimpeza[escolhaProduto - 1].preco / idiomas[lingua].first);
                                    carrinho.push_back(produtoLimpeza[escolhaProduto - 1]);
                                    cout << "\n" << produtoLimpeza[escolhaProduto - 1].nome << " تمت إضافته إلى العربة." << endl;
                                }
                            } while (escolhaProduto != 0);
                            break;
                
                        case 5:
                            cout<<"\nفي عربتك، لديك العناصر التالية:" << endl;
                            for(const auto & item : carrinho){
                                cout<< item.nome << " - " << fixed <<setprecision(2) << item.preco / idiomas[lingua].first << idiomas[lingua].second << endl;
                            }
                            cout <<"\nالسعر الإجمالي: "<<valorCompra<<idiomas[lingua].second<<endl;
                            break;
                    }
                } while (produto != 0);
                break;

            case 0:
                cout << "Programa encerrado." << endl;
                break;

            default:
                cout << "\nEscolha um idioma válido!" << endl;
        }

    carrinho.clear(); // para limpar o carrinho
    } while (lingua != 0);

    cout << "Código finalizado com sucesso." << endl;

    return 0;
}

