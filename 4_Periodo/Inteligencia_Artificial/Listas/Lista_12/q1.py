import os
os.environ['TF_ENABLE_ONEDNN_OPTS'] = '0'
import numpy as np
import tensorflow as tf
import matplotlib.pyplot as plt
from keras import layers, models
from keras.utils import load_img, img_to_array
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report, confusion_matrix

# --------------------------------------
# Configurações
# --------------------------------------

verbose = True

# ---------------------------------------
# 1. Preparação dos Dados
# ---------------------------------------

# Caminhos das imagens
dir_cat = "C:/Users/vinic/.cache/kagglehub/datasets/shaunthesheep/microsoft-catsvsdogs-dataset/versions/1/PetImages/Cat"
dir_dog = "C:/Users/vinic/.cache/kagglehub/datasets/shaunthesheep/microsoft-catsvsdogs-dataset/versions/1/PetImages/Dog"

# Parâmetros gerais
img_size = (150, 150)  # Tamanho padrão das imagens
batch_size = 32

# Pré-processamento de imagem: redimensionamento e normalização
def load_images_from_folder(folder, label, max_images=1000):
    images = []
    labels = []
    count = 0
    for filename in os.listdir(folder):
        path = os.path.join(folder, filename)
        try:
            img = load_img(path, target_size=img_size)  # Redimensiona a imagem
            img = img_to_array(img) / 255.0  # Converte para array e normaliza
            images.append(img)
            labels.append(label)
            count += 1
            if count >= max_images:
                break
        except:
            continue  # Ignora imagens corrompidas
    return images, labels

# Carregando imagens de gatos (0) e cachorros (1)
cat_images, cat_labels = load_images_from_folder(dir_cat, 0)
dog_images, dog_labels = load_images_from_folder(dir_dog, 1)
if verbose:
    print(f'Gatos: {len(cat_images)} imagens carregadas.')
    print(f'Cachorros: {len(dog_images)} imagens carregadas.')

# Unindo e embaralhando
X = np.array(cat_images + dog_images)
y = np.array(cat_labels + dog_labels)
if verbose:
    print(f'Total de imagens: {len(X)}')
    print(f'Total de rótulos: {len(y)}')

# Divisão: treino (70%), validação (15%), teste (15%)
X_train, X_temp, y_train, y_temp = train_test_split(X, y, test_size=0.3, random_state=42, stratify=y)
X_val, X_test, y_val, y_test = train_test_split(X_temp, y_temp, test_size=0.5, random_state=42, stratify=y_temp)
if verbose:
    print(f'Total de imagens: {len(X)}')
    print(f'Total de rótulos: {len(y)}')
    print(f'Treino: {len(X_train)} | Validação: {len(X_val)} | Teste: {len(X_test)}')

# Aumento de dados (data augmentation) para o treino
train_datagen = tf.keras.preprocessing.image.ImageDataGenerator(
    rotation_range=40,
    width_shift_range=0.2,
    height_shift_range=0.2,
    shear_range=0.2,
    zoom_range=0.2,
    horizontal_flip=True
)
if verbose:
    print("Data augmentation configurado para o conjunto de treino.")

# Geradores para treino, validação e teste
train_generator = train_datagen.flow(X_train, y_train, batch_size=batch_size)
val_generator = tf.keras.preprocessing.image.ImageDataGenerator().flow(X_val, y_val, batch_size=batch_size)
test_generator = tf.keras.preprocessing.image.ImageDataGenerator().flow(X_test, y_test, batch_size=batch_size, shuffle=False)
if verbose:
    print("Geradores criados para treino, validação e teste.")

# ---------------------------------------
# 2. Construção e Treinamento do Modelo CNN
# ---------------------------------------

# --- Arquitetura da CNN ---
model = models.Sequential([
    layers.Input(shape=(150, 150, 3)),  # Adicione esta linha
    layers.Conv2D(32, (3, 3), activation='relu'),
    layers.MaxPooling2D(2, 2),

    layers.Conv2D(64, (3, 3), activation='relu'),
    layers.MaxPooling2D(2, 2),

    layers.Conv2D(128, (3, 3), activation='relu'),
    layers.MaxPooling2D(2, 2),

    layers.Flatten(),
    layers.Dense(512, activation='relu'),
    layers.Dense(1, activation='sigmoid')
])
if verbose:
    print("Modelo CNN construído com sucesso.")
    model.summary()  # Exibe a arquitetura do modelo

# --- Compilação do modelo ---
model.compile(
    optimizer='adam',
    loss='binary_crossentropy',
    metrics=['accuracy']
)
if verbose:
    print("Modelo compilado com sucesso.")

# --- Treinamento do modelo ---
history = model.fit(
    train_generator,
    batch_size=batch_size,
    epochs=10,
    validation_data=val_generator
)
if verbose:
    print("Modelo treinado com sucesso.")
    
# ---------------------------------------
# 3. Avaliação e Testes
# ---------------------------------------

# --- Gráficos de acurácia e perda ---
plt.figure(figsize=(12, 5))

plt.subplot(1, 2, 1)
plt.plot(history.history['accuracy'], label='Acurácia Treino')
plt.plot(history.history['val_accuracy'], label='Acurácia Validação')
plt.title('Acurácia por Época')
plt.xlabel('Época')
plt.ylabel('Acurácia')
plt.legend()

plt.subplot(1, 2, 2)
plt.plot(history.history['loss'], label='Perda Treino')
plt.plot(history.history['val_loss'], label='Perda Validação')
plt.title('Perda por Época')
plt.xlabel('Época')
plt.ylabel('Perda')
plt.legend()

plt.tight_layout()
plt.show()

if verbose:
    print("Gráficos de acurácia e perda exibidos com sucesso.")

# --- Avaliação no conjunto de teste ---
test_generator.reset()
predictions = model.predict(test_generator)
y_pred = (predictions > 0.5).astype(int).flatten()
y_true = y_test

if verbose:
    print("\nRelatório de Classificação:")
    print(classification_report(y_true, y_pred, target_names=["Cat", "Dog"]))

    print("\nMatriz de Confusão:")
    print(confusion_matrix(y_true, y_pred))

    print("\nAcurácia no conjunto de teste:", np.mean(y_pred == y_true))
    print("Acurácia no conjunto de teste:", model.evaluate(test_generator)[1])

# ---------------------------------------
# 4. Teste com Imagens Novas (Opcional)
# ---------------------------------------

# --- Função para testar imagem externa ---
def testar_imagem(path):
    imagem = load_img(path, target_size=img_size)
    imagem_array = img_to_array(imagem) / 255.0
    imagem_array = np.expand_dims(imagem_array, axis=0)
    pred = model.predict(imagem_array)[0][0]
    classe = "Dog" if pred > 0.5 else "Cat"
    print(f"Imagem: {os.path.basename(path)} | Classificação: {classe} ({pred:.2f})")

# --- Testando imagens externas (exemplo) ---
if verbose:
    print("\nTestando imagens externas:")
    testar_imagem("C:/Users/vinic/.cache/kagglehub/datasets/shaunthesheep/microsoft-catsvsdogs-dataset/versions/1/PetImages/Cat/2001.jpg")
    testar_imagem("C:/Users/vinic/.cache/kagglehub/datasets/shaunthesheep/microsoft-catsvsdogs-dataset/versions/1/PetImages/Dog/2001.jpg")
    testar_imagem("C:/Users/vinic/.cache/kagglehub/datasets/shaunthesheep/microsoft-catsvsdogs-dataset/versions/1/PetImages/Cat/2002.jpg")
    testar_imagem("C:/Users/vinic/.cache/kagglehub/datasets/shaunthesheep/microsoft-catsvsdogs-dataset/versions/1/PetImages/Dog/2002.jpg")

