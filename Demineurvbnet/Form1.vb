Imports MesComposantsGraphiques.ButtonDemineur
Public Class Form1

    Private Row As Integer = 9
    Private Column As Integer = 9
    Private Grille(Row, Column) As MesComposantsGraphiques.ButtonDemineur
    Private PlateauDeJeu As New Plateau(Row, Column)
    Private NouvellePartie As New Button()
    Private ChangerGrille As New Button
    Private NbRow As New TextBox
    Private NbColum As New TextBox

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        InitPartie()
    End Sub

    ' Initialise une nouvelle partie, meme la premiere
    Private Sub InitPartie()
        ReDim Grille(Row, Column)
        PlateauDeJeu = New Plateau(Row, Column)
        ' on crée et place la grille de jeu
        Dim I, J As Integer
        Dim X, Y As Integer
        X = 3
        Y = 3
        For I = 0 To Row
            For J = 0 To Column
                Grille(I, J) = New MesComposantsGraphiques.ButtonDemineur(X, Y, PlateauDeJeu.Grille(I, J))
                Grille(I, J).Location = New Point(X, Y)
                Grille(I, J).Visible = True
                AddHandler Grille(I, J).MouseUp, AddressOf Me.Grille_Up
                Me.Controls.Add(Grille(I, J))
                X += 20
            Next
            X = 3
            Y += 20
        Next
        ' on cree le bouton pour la nouvelle partie
        NouvellePartie.Text = "NEW"
        NouvellePartie.Size = New Point(60, 20)
        NouvellePartie.Location = New Point((Column * 20 - 60) / 2, (Row * 20) + 30)
        AddHandler NouvellePartie.Click, AddressOf Me.NouvellePartie_Click
        Me.Controls.Add(NouvellePartie)

        ' on cree les parametres pour changer la taille de la grille
        ChangerGrille.Text = "New"
        ChangerGrille.Size = New Point(60, 20)
        NbColum.Size = New Point(60, 20)
        NbRow.Size = New Point(60, 20)
        NbColum.Location = New Point(10, (Row * 20) + 60)
        NbRow.Location = New Point(70, (Row * 20) + 60)
        ChangerGrille.Location = New Point(140, (Row * 20) + 60)
        AddHandler ChangerGrille.Click, AddressOf Me.ChangerGrille_Click
        Me.Controls.Add(ChangerGrille)
        Me.Controls.Add(NbColum)
        Me.Controls.Add(NbRow)

        ' Taille de la fenetre
        Size = New Point(Column * 25, (Row * 20) + 130)

    End Sub

    Private Sub Grille_Up(ByVal sender As System.Object, ByVal e As System.Windows.Forms.MouseEventArgs)
        ' click droit => drapeau
        If e.Button = Windows.Forms.MouseButtons.Right Then
            Dim I, J As Integer
            For I = 0 To Row
                For J = 0 To Column
                    If sender.Equals(Grille(I, J)) Then
                        If Grille(I, J).Enabled = True Then
                            If Grille(I, J).BackColor = Color.ForestGreen Then
                                Grille(I, J).BackColor = Color.LightGray
                            Else
                                Grille(I, J).BackColor = Color.ForestGreen
                            End If
                        End If
                        End If
                Next
            Next

        Else
            'click gauche
            Dim I, J As Integer
            For I = 0 To Row
                For J = 0 To Column
                    If sender.Equals(Grille(I, J)) And Grille(I, J).BackColor <> Color.ForestGreen Then
                        ' Appeler les cases voisines à se dévoiler si la case courante = 0
                        If PlateauDeJeu.Grille(I, J) = 0 Then
                            Propager(I, J)
                        ElseIf Grille(I, J).NbVoisins = -1 Then
                            Grille(I, J).ChangeEtat()
                            MsgBox("Perdu :(")
                            ' on désactive tous les boutons de la grille
                            Dim x, y As Integer
                            For x = 0 To Row
                                For y = 0 To Column
                                    Grille(x, y).Enabled = False
                                Next
                            Next
                        Else
                            Grille(I, J).ChangeEtat()
                        End If
                    End If
                Next
            Next
        End If
    End Sub

    Private Sub Propager(ByVal I As Integer, ByVal J As Integer)
        If PlateauDeJeu.Grille(I, J) <> 0 Then
            If PlateauDeJeu.Grille(I, J) <> -1 Then
                If Grille(I, J).Enabled = True Then
                    Grille(I, J).ChangeEtat()
                End If
            End If
        ElseIf Grille(I, J).Enabled = True And Grille(I, J).NbVoisins = 0 And Grille(I, J).BackColor <> Color.ForestGreen Then
            Grille(I, J).ChangeEtat()
            Dim XMax, XMin, YMin, YMax As Integer
            PlateauDeJeu.Bornes(I, J, XMin, XMax, YMin, YMax)
            Dim K, L As Integer
            For K = XMin To XMax
                For L = YMin To YMax
                    'If K <> I And L <> J Then
                    Propager(K, L)
                    'End If
                Next
            Next
        End If
    End Sub

    Private Sub ChangerGrille_Click(ByVal sender As Object, ByVal e As EventArgs)
        ' effacer tout le form
        Me.Controls.Clear()
        Row = Val(NbRow.Text) - 1
        Column = Val(NbColum.Text) - 1
        InitPartie()
    End Sub

    Private Sub NouvellePartie_Click(ByVal sender As Object, ByVal e As EventArgs)
        ' effacer tout le form
        Me.Controls.Clear()
        InitPartie()
    End Sub

End Class
