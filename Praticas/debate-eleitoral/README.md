# Projeto Debate Eleitoral

Projeto para criar um sistema para gerenciamento de debate eleitoral.

A UML do sistema pode ser vista em [UML Debate Eleitoral](docs/UML.pdf).


## Como rodar

Primeiro rodo o seguinte comando no seu terminal, caso não exista, crie antes um diretório `build/` na raiz do projeto `debate-eleitoral`, e depois: 

```bash
make app
```

Em seguida execute com

```bash
make run
```

## Observar Logs 

Para acompanhar os logs abra um outro terminal e na raiz do diretório do projeto rode o comando

```bash
tail -f app.log
```