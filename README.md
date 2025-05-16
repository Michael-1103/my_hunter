# 🎯 my_hunter

**my_hunter** est un petit jeu de tir en 2D développé en C, utilisant la **CSFML** (la version C de la SFML). Le but du jeu est de viser et tirer sur des canards qui volent à l’écran.

---

## 🕹️ Fonctionnement du jeu

- Des canards apparaissent et volent à l'écran.
- Cliquez avec la souris pour tirer.
- Chaque canard touché rapporte des points.
- Si vous ratez trop de cibles, c’est perdu !
- Une animation de victoire est affichée lorsque vous atteignez le score cible.

---

## ✅ Prérequis

Avant de compiler et lancer le jeu, assurez-vous d’avoir installé :

- Un système GNU/Linux
- Un compilateur C (`gcc`)
- La bibliothèque **CSFML** (version 2.5 ou supérieure)

### Installer CSFML (exemple pour Ubuntu/Debian) :

```bash
sudo apt-get install libcsfml-dev
```

---

## ⚙️ Compilation

Le projet contient un `Makefile`. Pour compiler le jeu, utilisez la commande :

```bash
make
```

Cela génère un exécutable nommé `my_hunter`.

---

## 🚀 Lancement

Après compilation, lancez le jeu avec :

```bash
./my_hunter
```

---

## 📁 Structure du projet

```
my_hunter/
├── include/           # Dossiers du header
│   └── *.h            # Fichiers headers
├── src/               # Dossiers sources du jeu
│   └── *.c            # Fichiers sources
├── ressources/
│   ├── fonts/         # Polices du jeu
│   └── music/         # Sons du jeu
├── Makefile
└── README.md
```

---

## 🎨 Ressources intégrées

- Sons : `ressources/music/duck.ogg`, `kill.ogg`
- Polices personnalisées : dans `ressources/fonts/`

---

## 👨‍💻 Auteur

Projet réalisé dans le cadre de l’école **EPITECH**, inspiré du jeu Duck Hunt.

---

Bon jeu, et visez juste ! 🦆🎯