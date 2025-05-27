import 'package:app/ui/widgets/movie_row.dart';
import 'package:flutter/material.dart';
import 'package:app/utils/utils.dart';

typedef OnMovieTap = void Function(int movieId);

class VerticalMovieList extends StatelessWidget {
  final List<String> movies;
  final OnMovieTap onMovieTap;

  const VerticalMovieList({
    super.key,
    required this.movies,
    required this.onMovieTap,
  });

  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        MoviewRow(movie: movies[0]),
        addVerticalSpace(10),
        MoviewRow(movie: movies[1]),
      ],
    );
  }
}
