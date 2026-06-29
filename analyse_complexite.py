import pandas as pd
import matplotlib.pyplot as plt

# Chargement des données
df = pd.read_csv("mesures.csv", sep=";")

methodes = ["naif", "definition", "infixe"]

groupes = [
    ("ABR_presque_complet", "non_ABR_presque_complet"),
    ("ABR_filiforme",        "non_ABR_filiforme"),
    ("ABR_quelconque",       "non_ABR_quelconque")
]

titres = ["Presque complet", "Filiforme", "Quelconque"]

couleurs = {
    "naif":       "blue",
    "definition": "green",
    "infixe":     "red"
}

for idx, (abr, non_abr) in enumerate(groupes):
    fig, axes = plt.subplots(2, 3, figsize=(15, 10))

    for ligne, morph in enumerate([abr, non_abr]):
        data_morph = df[df["Morphologie"] == morph]

        # -- Colonne 0 : Nb noeuds visités --
        ax = axes[ligne][0]
        for methode in methodes:
            data_meth = data_morph[data_morph["Methode"] == methode]
            moyenne = data_meth.groupby("Taille")["Nb_visites"].mean()
            ax.plot(moyenne.index, moyenne.values,
                    marker='o', label=methode, color=couleurs[methode])
        ax.set_title(f"{morph}")
        ax.set_xlabel("Taille (n)")
        ax.set_ylabel("Nb noeuds visités")
        ax.legend()
        ax.grid(True)

        # -- Colonne 1 : Temps --
        ax = axes[ligne][1]
        for methode in methodes:
            data_meth = data_morph[data_morph["Methode"] == methode]
            moyenne = data_meth.groupby("Taille")["Temps"].mean()
            ax.plot(moyenne.index, moyenne.values,
                    marker='o', label=methode, color=couleurs[methode])
        ax.set_title(f"{morph}")
        ax.set_xlabel("Taille (n)")
        ax.set_ylabel("Temps (s)")
        ax.legend()
        ax.grid(True)

        # -- Colonne 2 : Temps log/log --
        ax = axes[ligne][2]
        for methode in methodes:
            data_meth = data_morph[data_morph["Methode"] == methode]
            moyenne = data_meth.groupby("Taille")["Temps"].mean()
            ax.plot(moyenne.index, moyenne.values,
                    marker='o', label=methode, color=couleurs[methode])
        ax.set_title(f"{morph}")
        ax.set_xlabel("Taille (n)")
        ax.set_ylabel("Temps (s)")
        ax.set_xscale("log")
        ax.set_yscale("log")
        ax.legend()
        ax.grid(True)

    plt.suptitle(f"Analyse - {titres[idx]}", fontsize=16)
    plt.tight_layout()
    plt.savefig(f"analyse_{titres[idx].lower().replace(' ', '_')}.png")
    plt.show()
