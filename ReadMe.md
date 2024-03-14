# Interfaces pour le projet Arcade

## Comment l'utiliser sur votre propre repository ?

Vous pouvez importer ce repository en tant que sous-module de votre propre repository. Pour cela, suivez le court tutoriel qui suit.

### Importer ArcadeInterface en tant que sous-module

> Sauf précision de notre part, veuillez exécuter les commandes depuis la racine de votre repository.

Pour importer un sous-module sur votre repository vous devez utiliser la suite de commande `git submodule`.

#### Créer le sous-module

Premièrement il faut ajouter le module à votre projet.

```
git submodule add git@github.com:ASM-Studios/ArcadeInterfaces.git
```

> **N'utilisez pas l'adresse http du projet pour créer votre module !**

Vous pouvez vérifier que la commande s'est correctement exécutée avec un `git status`. En effectuant `git status` vous devriez obtenir un output semblable au suivant :

```
Sur la branche main
Votre branche est à jour avec 'origin/main'.

Modifications qui seront validées :
  (utilisez "git restore --staged <fichier>..." pour désindexer)
	nouveau fichier : .gitmodules
	nouveau fichier : ArcadeInterfaces

```

L'information importante à remarquer est la création du fichier `.gitmodules` et du dossier `ArcadeInterfaces`. Le fichier `.gitmodules` est le fichier de configuration des sous-modules de votre repository. Le dossier `ArcadeInterfaces` est celui qui contiendra tout le code de notre sous-module.

#### Comment corriger l'adresse de mon sous-module ?

> Si vous n'avez pas encore rencontré de problèmes, passez cette étape.

Si vous avez renseigné une mauvaise adresse pour un sous-module, notamment si vous avez utilisé une adresse http au lieu d'une adresse ssh, vous avez deux solutions :

- soit vous recommencez à zéro en supprimant les fichiers et dossiers créés par `git submodule add`
- soit vous modifiez la configuration du fichier `.gitmodules`

Voyons comment effectuer la deuxième option.

Commencez par ouvrir le fichier `.gitmodules`. Vous devriez voir quelque chose de similaire à ça :

```
[submodule "ArcadeInterfaces"]
	path = ArcadeInterfaces
	url = git@github.com:ASM-Studios/ArcadeInterfaces.git
```

Ce que vous voyez est la déclaration du sous-module ArcadeInterfaces.
- La variable `path` correspond au chemin jusqu'au dossier qui contient le sous-module à partir de la racine de votre repository. Vous pouvez donc déplacer et renommer le dossier ArcadeInterfaces du moment que vous mettez à jour le `path` du `.gitmodules`.
- La variable `url` correspond à l'url utilisée pour cloner le repository du sous-module. Pour importer notre sous-module vous devez mettre `git@github.com:ASM-Studios/ArcadeInterfaces.git` comme url.

Une fois que vous avez effectué vos modifications sur `.gitmodules` vous devez synchroniser vos sous-modules sur la nouvelle configurations. Pour cela utilisez la commande suivante :

```
git submodule sync --recursive
```

Normalement à ce stade là votre sous-module est près pour continuer le tutoriel.

#### Importer les fichiers du sous-module

Normalement à ce stade du tutoriel, le dossier du sous-module sur votre repository est vide.
Pour importer les fichiers vous devez initialiser le sous-module avec la commande suivante :

```
git submodule init ./ArcadeInterfaces/
```

Normalement à ce stade là le dossier du sous-module ressemble à ce qu'aurait donné un "git clone" de son repository.

### Mettez à jour régulièrement le sous-module

Le sous-module du ArcadeInterfaces que vous avez créé sur votre repository fonctionne comme un repository. Cela implique que la gestion des fichiers est asynchrone aussi.

Sur un repository classique il suffit d'effectuer la commande "git pull" pour récupérer les dernières modifications en local sur votre machine.

Pour un sous-module c'est un poil plus subtil. Vous devez d'abord récupérer les dernières modifications en local du sous-module. Et ensuite vous devez commit ces modifications pour mettre à jour la version du sous-module de votre projet sur GitHub.

Pour cela vous devez d'abord effectuer la commande suivante :

```
git submodule update --remote
```

Cette commande récupère les dernières modifications d'un sous-module un peu comme un "git pull".

Ensuite vous envoyez ces modifications sur le votre repository :

```
git add .gitmodules ArcadeInterface/
git commit -m "[FIX] mise à jour du sous-module ArcadeInterfaces"
git push
```

Si tout s'est bien passé vous devriez obtenir une sortie similaire avec un `git status` :

```
Sur la branche main
Votre branche est à jour avec 'origin/main'.

rien à valider, la copie de travail est propre
```

Si vous n'avez pas réussi à effectuer l'une des commandes précédentes :
- vérifiez qu'il n'y a pas un conflit sur la branche sur laquelle vous travaillez
- vérifiez si la configuration de l'adresse du module est conforme

### Modifier le sous-module que vous avez importer dans votre repository

> Avant tout, vérifier avec le propriétaire du repository du module ArcadeInterfaces que vous avez le droit d'éditer le projet.

Comme mentionné précédemment, un sous-module ressemble fortement à un repository. Vous pouvez en réalité utiliser toutes les fonctionnalités d'un repository classique à l'intérieur d'un sous-module.

Donc pour commit une modification locale de votre sous-module sur le repository de ArcadeInterfaces il vous suffit de vous déplacer à la racine du sous-module avec `cd` puis d'effectuer les commandes classiques du genre :

```
git add *
git commit -m "description du commit"
git push
```


