# 🎮 so_long

**so_long** est un projet de création d’un petit jeu 2D en C, utilisant la MiniLibX pour l’affichage graphique.  
Le joueur contrôle un personnage qui doit collecter tous les objets disséminés dans la carte avant d’atteindre la sortie.

---

## 🎯 Objectifs

- Apprendre à manipuler la MiniLibX pour créer une interface graphique simple  
- Gérer les événements clavier pour déplacer le joueur  
- Lire et valider une carte de jeu depuis un fichier `.ber`  
- Implémenter la logique de collecte d’objets et de fin de niveau  

---

## ⚙️ Compilation

Le projet est compilé via Makefile. Pour compiler :

```bash
make
```
L’exécutable so_long sera créé.

---

## 🚀 Usage
```bash
./so_long path/to/map.ber
```
- La carte doit être un fichier .ber valide respectant les règles définies dans le sujet (murs, joueur, objets, sortie).

- Le joueur utilise les touches directionnelles pour se déplacer.

---

## 📄 Règles du jeu
- Le joueur doit collecter tous les objets (C)

- Puis atteindre la sortie (E)

- Les déplacements sont comptabilisés et affichés dans la console

- La carte doit être entourée de murs (1) pour être valide

---

## 📌 Remarques
Ce projet a été réalisé dans le cadre du cursus de l’École 42.
Il permet de s’initier à la programmation graphique et à la gestion des événements en C.
