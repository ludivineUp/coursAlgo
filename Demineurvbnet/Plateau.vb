Public Class Plateau

    Public Property Grille As Integer(,) = _Grille
    Public Property Row As Integer = _Row
    Public Property Colunm As Integer = _Colunm
    Public Property NbMines As Integer = _NbMines

    Sub New(ByVal X As Integer, ByVal Y As Integer)
        _Row = X
        _Colunm = Y
        ReDim Grille(X, Y)
        NbMines = (X + 1) * (Y + 1) / 100 * 10 ' 10% des cases sont minées
        InitialiserMines()
        CalculVoisin()
    End Sub

    Private Sub InitialiserMines()
        Dim Aleatoire As New Random
        Dim I As Integer
        For I = 0 To NbMines - 1
            Dim X, Y As Integer
            X = Aleatoire.Next(_Row)
            Y = Aleatoire.Next(_Colunm)
            If _Grille(X, Y) = -1 Then
                ' la mine est déjà présente
                I = I - 1
            Else
                ' on place la mine
                _Grille(X, Y) = -1
            End If
        Next
    End Sub

    Private Sub CalculVoisin()
        Dim I, J As Integer
        For I = 0 To _Row
            For J = 0 To _Colunm
                Dim Sum, XMin, XMax, YMin, YMax, K, L As Integer
                Sum = 0
                ' quelles sont les cases voisines
                Bornes(I, J, XMin, XMax, YMin, YMax)
                For K = XMin To XMax
                    For L = YMin To YMax
                        If Grille(K, L) = -1 Then
                            Sum += 1
                        End If
                    Next
                Next
                ' on ne modifie la case que si ce n'est pas une mine
                If Grille(I, J) <> -1 Then
                    Grille(I, J) = Sum
                End If
            Next
        Next
    End Sub

    Public Sub Bornes(ByVal X As Integer, ByVal Y As Integer, ByRef XMin As Integer, ByRef XMAx As Integer, ByRef YMin As Integer, ByRef YMax As Integer)
        If X - 1 > 0 Then
            XMin = X - 1
        Else
            XMin = 0
        End If
        If X < _Row Then
            XMAx = X + 1
        Else
            XMAx = X
        End If
        If Y - 1 > 0 Then
            YMin = Y - 1
        Else
            YMin = 0
        End If
        If Y < _Colunm Then
            YMax = Y + 1
        Else
            YMax = Y
        End If
    End Sub


End Class
