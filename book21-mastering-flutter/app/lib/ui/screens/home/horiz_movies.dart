import 'package:app/providers.dart';
import 'package:cached_network_image/cached_network_image.dart';
import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';

class HorizontalMovies extends ConsumerWidget {
  const HorizontalMovies({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final movies = ref.watch(movieImagesProvider);
    return SizedBox(
      height: 142,
      child: ListView.builder(
        scrollDirection: Axis.horizontal,
        itemCount: movies.length,
        itemBuilder: (context, index) {
          return GestureDetector(
            onTap: () {},
            child: SizedBox(
              width: 100,
              height: 142,
              child: CachedNetworkImage(
                imageUrl: movies[index],
                alignment: Alignment.topCenter,
                fit: BoxFit.fitHeight,
                height: 100,
                width: 142,
              ),
            ),
          );
        },
      ),
    );
  }
}
