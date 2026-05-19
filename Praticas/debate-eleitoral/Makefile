# Compiladores
CXX = g++

# Flags
CXXFLAGS = -std=c++20 -Wall -O2
INCLUDES = -Iinclude

# Diretórios
SRC_DIR = src
BUILD_DIR = build

# Arquivos
SRC = $(shell find $(SRC_DIR) -name "*.cpp")
TARGET = $(BUILD_DIR)/programa

# Regra principal
app: $(TARGET)

# Criar build/ se não existir
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compilar tudo (C++)
$(TARGET): $(SRC) 
	$(CXX) $(SRC) $(INCLUDES) $(CXXFLAGS) -o $(TARGET)

# Executa o programa
run: app
	./$(TARGET)

# Limpar build
clean:
	rm -rf $(BUILD_DIR)